//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include "NsVar.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner), DBI(ADOConnection)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	INI.Load(ExtractFilePath(Application->ExeName) + "settings.ini");

	try{
		if (ADOConnection->Connected)
			ADOConnection->Close();
		ADOConnection->ConnectionString = "FILE NAME=" + ToString(INI["ADO::UDL"]);
		ADOConnection->Open();

	}catch(Exception& e){
		Application->MessageBox(("データベース接続に失敗しました - [計量データ都度出力]\r\n" + e.Message).c_str(), "エラー", MB_OK | MB_ICONSTOP);
		Close();
        return;
	}

    local_path_				= ToString(INI["Output::LocalPath"]);
    delete_local_file_		= ToInt(INI["Output::DeleteLocalFile"]) == 1 ? true : false;
    copy_file_				= ToInt(INI["Output::Copy"]) == 1 ? true : false;
    copy_path_				= ToString(INI["Output::CopyPath"]);
    output_keiryo_			= ToInt(INI["Output::Keiryo"]) == 1 ? true : false;
    output_tran_    		= ToInt(INI["Output::Tran"]) == 1 ? true : false;
	OutputTimer->Interval 	= ToInt(INI["Output::interval"]);
    mode_					= ToString(INI["Output::mode"]).ToIntDef(1);	// mode = 1 :: 計量結果をポスト→事務所 ／ mode = 2 :: 伝票発行命令を事務所→ポスト

    // ディレクトリチェック
    if (!DirectoryExists(local_path_)){
        if (!CreateDirectory(local_path_.c_str(), 0)){
            Application->MessageBox("ローカル出力パスを設定してください", "計量データ都度出力", MB_OK | MB_ICONSTOP);
            Close();
        }
    }

    if (copy_file_){
	    if (!DirectoryExists(copy_path_)){
    	    if (!CreateDirectory(copy_path_.c_str(), 0)){
        	    Application->MessageBox("出力パスを設定してください", "計量データ都度出力", MB_OK | MB_ICONSTOP);
            	Close();
            }
        }
    }

    // "出力区分"フィールドチェック
    std::auto_ptr<TStringList> fields(new TStringList());
	ADOConnection->GetFieldNames("D_計量", fields.get());
    if (fields->IndexOf("出力区分") == -1){
    	if (Application->MessageBox("[D_計量]に[出力区分]がありません\r\n作成してよろしいですか？\r\nいいえを選択するとプログラムを終了します", "計量データ都度出力", MB_YESNO | MB_ICONEXCLAMATION) != IDYES){
			OutputTimer->Enabled = false;
        	CloseTimer->Enabled  = true;;
            return;
        }
    	DBI.Execute("ALTER TABLE D_計量 ADD 出力区分 int NOT NULL default 0");
    }

    fields->Clear();
	ADOConnection->GetFieldNames("D_取引", fields.get());
    if (fields->IndexOf("出力区分") == -1){
    	DBI.Execute("ALTER TABLE D_取引 ADD 出力区分 int NOT NULL default 0");
    }

    if (!CloseTimer->Enabled)
		OutputTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OutputTimerTimer(TObject *Sender)
{
	OutputTimer->Enabled = false;

    AnsiString sql;
    NsRecordSet set;
    std::ofstream ofs;
    TDateTime now = Now();
    std::auto_ptr<TStringList> fields(new TStringList());
    std::auto_ptr<TStringList> record(new TStringList());
    std::auto_ptr<TStringList> id_list(new TStringList());
    Variant var;
    AnsiString val;
    AnsiString local_file, copy_file;

    INI.Reload();

    // 計量データ
    if (output_keiryo_){

        // 計量データ取得
        set.clear();
        if (mode_ == 1){
    	    // フィールド名
            ADOConnection->GetFieldNames("D_計量", fields.get());

			sql = 	"SELECT * FROM D_計量 WHERE 完了区分 = 1 AND 出力区分 = 0";	// 出力区分 0:未出力（ポスト→事務所）

        }else{
    	    // フィールド名
            fields->CommaText="計量ID,拠点ID,計量日,伝票No,行No,車番,得意先コード,得意先略称,項目1コード,項目1略称,項目2コード,項目2略称,品目コード,品目略称,1回目重量,2回目重量,正味重量,計量日時2,搬入出区分";

			sql = 	"SELECT	計量ID, 拠点ID, 計量日, 伝票No, 行No, 車番, 得意先コード, 得意先略称, 項目1コード, 項目1略称, 項目2コード, 項目2略称, 品目コード, 品目略称, [1回目重量], [2回目重量], 正味重量, 計量日時2, 搬入出区分 "
            		"FROM	V_計量 "
            		"WHERE	完了区分 = 1 AND 計量ID IN (SELECT 計量ID FROM D_計量 WHERE 出力区分 = 2)";
                    // 出力区分 2:伝票発行（事務所→ポスト）
        }

        if (!DBI.GetRecordSet(sql, set)){
			OutputTimer->Enabled = true;
        	return;
        }

        if (mode_ == 1){
	        local_file = local_path_ + "\\D_計量-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
    	    copy_file  = copy_path_  + "\\D_計量-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
        }else{
	        local_file = local_path_ + "\\W_伝票-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
    	    copy_file  = copy_path_  + "\\W_伝票-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
        }
        ofs.open(local_file.c_str());

        // タイトル出力 ※出力しないように修正 12/11
		//ofs << fields->CommaText.c_str() << std::endl;

        // データ出力
		id_list->Clear();
        for (unsigned int row = 0; row < set.size(); row++){
            record->Clear();
           	id_list->Add(ToString(set[row]["計量ID"]));	// 計量IDを追加
			for (int i = 0; i < fields->Count; i++){
                var = set[row][fields->Strings[i]];
                if (var.IsNull())
                    val = "@NULL@";
       	        else
           	        val = ToString(var);
            	record->Append(val);
    	    }
			ofs << record->CommaText.c_str() << std::endl;
        }
        ofs.close();

        // 出力済みに設定
        DBI.Execute("UPDATE D_計量 SET 出力区分 = 1 WHERE 計量ID IN ("+ id_list->CommaText +")");

        // ローカル出力パス→出力パス
        if (copy_file_)
			CopyFile(local_file.c_str(), copy_file.c_str(), false);

        // ローカルファイルを削除
        if (delete_local_file_)
        	DeleteFile(local_file);
    }

   	// 取引データ出力
    if (output_tran_ && mode_ == 1){
    	// フィールド名
        ADOConnection->GetFieldNames("D_取引", fields.get());

        // 取引データ取得
        set.clear();
		sql = "SELECT * FROM D_取引 WHERE 完了区分 = 1 AND 出力区分 = 0";
        if (!DBI.GetRecordSet(sql, set)){
			OutputTimer->Enabled = true;
        	return;
        }

        local_file = local_path_ + "\\D_取引-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
        copy_file  = copy_path_  + "\\D_取引-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
        ofs.open(local_file.c_str());

        // タイトル出力 ※出力しないように修正 12/11
		//ofs << fields->CommaText.c_str() << std::endl;

        // データ出力
        id_list->Clear();
        for (unsigned int row = 0; row < set.size(); row++){
            record->Clear();
           	id_list->Add(ToString(set[row]["取引ID"]));	// 取引IDを追加
			for (int i = 0; i < fields->Count; i++){
                var = set[row][fields->Strings[i]];
                if (var.IsNull())
                    val = "@NULL@";
       	        else
           	        val = ToString(var);
            	record->Append(val);
    	    }
			ofs << record->CommaText.c_str() << std::endl;
        }
        ofs.close();

        // 出力済みに設定
        DBI.Execute("UPDATE D_取引 SET 出力区分 = 1 WHERE 取引ID IN ("+ id_list->CommaText +")");

        // ローカル出力パス→出力パス
        if (copy_file_)
			CopyFile(local_file.c_str(), copy_file.c_str(), false);

        // ローカルファイルを削除
        if (delete_local_file_)
        	DeleteFile(local_file);
    }

	OutputTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExitItemClick(TObject *Sender)
{
    if (Application->MessageBox("計量データ都度出力を終了しますか？", Caption.c_str(), MB_YESNO | MB_ICONWARNING | MB_TOPMOST) == IDYES)
        Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseTimerTimer(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

