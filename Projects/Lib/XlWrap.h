/**
 * XlWrap.h: BCB用 Excel Wrapper クラス
 *
 * 実行例1 メモリ上のセルデータを書き込む。
 *	XlBook book(ExtractFilePath(Application->ExeName) + "原本.xls");
 *
 *	Cells cells;
 *	cells[5][10] = 200;
 *
 *	try{
 *		book.open(true);
 *
 *		book.setCellsToSheet("内訳表", cells);
 *
 *		book.run("TestMacro");
 *	}catch(Exception& e){
 *		ShowMessage(e.Message);
 *		book.quit();
 *	}
 *	book.close();
 *
 * 実行例2 シートをコピーし名前を変え、メモリ上のセルデータを書き込む。
 *	XlBook book(ExtractFilePath(Application->ExeName) + "原本.xls");
 *
 *	Cells cells;
 *	cells[5][10] = 200;
 *
 *	try{
 *		book.open(true);
 *
 *		Variant sheet = book.getWorksheet("内訳表");
 *		book.copySheet(sheet, 1);
 *
 *		sheet = book.getWorksheet(1);
 *		book.changeSheetName(sheet, "内訳表その2");
 *
 *		book.setCellsToSheetObj(sheet, cells);
 *
 *		book.run("TestMacro");
 *	}catch(Exception& e){
 *		ShowMessage(e.Message);
 *		book.quit();
 *	}
 *	book.close();
 */

#ifndef XlWrap_H_
#define XlWrap_H_

#include <map>

typedef std::map<int, AnsiString> Cols;
typedef std::map<int, Cols> Cells;

class XlBook{
public:
	XlBook(const AnsiString& filename)
		: opened_(false), filename_(filename) {}
	virtual ~XlBook(){close();}

	void open(bool visible = true){
		xlAppObj_ = Variant::CreateObject("Excel.Application");
		xlApp_ = xlAppObj_.Exec(PropertyGet("Application"));
		setVisible(visible);
		xlWorkbooks_ = xlAppObj_.Exec(PropertyGet("Workbooks"));
		xlWorkbook_ = xlWorkbooks_.Exec(Procedure("Open") << filename_);
		xlWorksheets_ = xlApp_.Exec(PropertyGet("WorkSheets"));
		opened_ = true;
	}
	void open(Variant app_obj, bool visible = true){
		xlAppObj_ = app_obj;
		xlApp_ = xlAppObj_.Exec(PropertyGet("Application"));
		setVisible(visible);
		xlWorkbooks_ = xlAppObj_.Exec(PropertyGet("Workbooks"));
		xlWorkbook_ = xlWorkbooks_.Exec(Procedure("Open") << filename_);
		xlWorksheets_ = xlApp_.Exec(PropertyGet("WorkSheets"));
		opened_ = true;
	}

	void close(){
		xlAppObj_ = Unassigned;
		xlApp_ = Unassigned;
		xlWorkbooks_ = Unassigned;
		xlWorkbook_ = Unassigned;
		xlWorksheets_ = Unassigned;
		opened_ = false;
	}

	void setVisible(bool visible){
		xlAppObj_.Exec(PropertySet("Visible") << (visible ? "true" : "false"));
	}

	void setCellsToSheet(const AnsiString& sheet, const Cells& cells){
		Variant worksheet = getWorksheet(sheet);
		Variant cell;

		for (Cells::const_iterator row = cells.begin(); row != cells.end(); row++){
			for (Cols::const_iterator col = row->second.begin(); col != row->second.end(); col++){
				cell = worksheet.Exec(PropertyGet("Cells") << row->first << col->first);
				cell.Exec(PropertySet("Value") << col->second.c_str());

			}
		}
	}

	void setCellsToSheetObj(Variant sheet, const Cells& cells){
		Variant cell;

		for (Cells::const_iterator row = cells.begin(); row != cells.end(); row++){
			for (Cols::const_iterator col = row->second.begin(); col != row->second.end(); col++){
				cell = sheet.Exec(PropertyGet("Cells") << row->first << col->first);
				cell.Exec(PropertySet("Value") << col->second.c_str());

			}
		}
	}

	void copySheet(Variant sheet, int insert_pos){
		sheet.Exec(Procedure("Copy") << xlApp_.Exec(PropertyGet("Sheets") << insert_pos));
	}

	void run(const AnsiString& macro){
		xlApp_.Exec(Function("Run") << macro);
	}
	void quit(){
		if (opened_)
			xlAppObj_.OleProcedure("Quit");
		close();
	}

	Variant getAppObj() {return xlAppObj_;}
	Variant getApplication() {return xlApp_;}
	Variant getWorkbooks() {return xlWorkbooks_;}
	Variant getWorkbook() {return xlWorkbook_;}
	Variant getWorksheets() {return xlWorksheets_;}

	Variant getWorksheet(const AnsiString& sheet_name)
		{return xlWorksheets_.Exec(PropertyGet("Item") << sheet_name);}
	Variant getWorksheet(int page)
		{return xlAppObj_.Exec(PropertyGet("WorkSheets") << page);}
	void changeSheetName(Variant sheet, const AnsiString& new_name)
		{sheet.Exec(PropertySet("Name") << new_name);}

private:
	bool opened_;
	AnsiString filename_;
	Variant xlAppObj_;
	Variant xlApp_;
	Variant xlWorkbooks_;
	Variant xlWorkbook_;
	Variant xlWorksheets_;
};

AnsiString toXlColumnName(int col){
	static AnsiString alph("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	if (col < 1 || col > 702)
		return "";
	int quotient = (col - 1) / 26;
	int remainder = ((col - 1) % 26) + 1;

	if (quotient)
		return AnsiString(alph[quotient]) + AnsiString(alph[remainder]);
	else
		return alph[remainder];
}

int getMaxCol(const Cells& cells){
	int max = 0;
	for (Cells::const_iterator row = cells.begin(); row != cells.end(); row++)
		for (Cols::const_iterator col = row->second.begin(); col != row->second.end(); col++)
			max = std::max(max, col->first);
	return max;
}

int getMaxRow(const Cells& cells){
	int max = 0;
	for (Cells::const_iterator row = cells.begin(); row != cells.end(); row++)
		max = std::max(max, row->first);
	return max;
}

#endif	//XlWrap_H_
