/**
  * NsIni.h: NikkoSoftware INI File Acccess Library Header
  *
  *     @author a_oshima
  *     @history
  *                 2007-10-13  作成
  *                 2007-10-30  operator[] の返値を Variant に変更
  *                 2011-07-13  SaveSingle メソッド追加
  */

#ifndef NsIni_H_
#define NsIni_H_

#include <IniFiles.hpp>
#include <map>
#include <memory>

class NsIni{
    typedef std::map<AnsiString, Variant> KeyValue;
    typedef std::map<AnsiString, KeyValue> IniImage;
public:
    NsIni(const AnsiString& separator = "::"){
        separator_ = separator;
    }
    virtual ~NsIni() {}

    void Load(const AnsiString& ini_filename){
        ini_filename_ = ini_filename;
        ini_image_.clear();

        std::auto_ptr<TIniFile> ini(new TIniFile(ini_filename));
        std::auto_ptr<TStringList> sections(new TStringList());
        std::auto_ptr<TStringList> keys(new TStringList());
        AnsiString section, key;

        ini->ReadSections(sections.get());
        for (int i = 0; i < sections->Count; i++){
            ini->ReadSection(sections->Strings[i], keys.get());
            for (int k = 0; k < keys->Count; k++){
                section = sections->Strings[i];
                key     = keys->Strings[k];

                ini_image_[section][key] = ini->ReadString(section, key, AnsiString());
            }
        }

    }
    void Reload()
        {Load(ini_filename_);}

    void Save(){
        std::auto_ptr<TIniFile> ini(new TIniFile(ini_filename_));
        for (IniImage::iterator i = ini_image_.begin(); i != ini_image_.end(); i++){
            for (KeyValue::iterator j = i->second.begin(); j != i->second.end(); j++){
                ini->WriteString(i->first, j->first, j->second);
            }
        }
    }

    void SaveSingle(const AnsiString& sec, const AnsiString& key, const AnsiString& val){
        std::auto_ptr<TIniFile> ini(new TIniFile(ini_filename_));
        ini->WriteString(sec, key, val);
    }

    Variant& operator[](const AnsiString& sec_key){
        AnsiString section;
        AnsiString key(sec_key);

        int index = key.AnsiPos(separator_);
        if (index < 1){
            section = "Default";
        }else{
            section = key.SubString(1, index - 1);
            key.Delete(1, index + separator_.Length() - 1);
        }

        return ini_image_[section][key];
    }

    void Debug(){
        for (IniImage::iterator i = ini_image_.begin(); i != ini_image_.end(); i++){
            for (KeyValue::iterator j = i->second.begin(); j != i->second.end(); j++){
                ShowMessage(i->first + separator_ + j->first + "=" + j->second);
            }
        }
    }
private:
    IniImage ini_image_;
    AnsiString ini_filename_;
    AnsiString separator_;
};

#endif  //NsIni_H_
