/**
  * NsConfig.h: NikkoSoftware Configuration Class Header
  *
  *     @author a_oshima
  *     @history
  *                 2008-09-16  çÏê¨
  */

#ifndef NsConfig_H_
#define NsConfig_H_

#include "NsDB.h"
#include <map>
#include <memory>

class NsConfig{
	typedef std::map<AnsiString, Variant> Configuration;
public:
	NsConfig() {}
	virtual ~NsConfig() {}

	void Load(NsDBInterface *DBI, const AnsiString& table = "M_êßå‰", const AnsiString& key_field = "ê›íËñº", const AnsiString& val_field = "ê›íËíl"){
		config_.clear();

		AnsiString sql = "SELECT " + key_field + ", " + val_field + " FROM " + table;
		NsRecordSet set;

		DBI->GetRecordSet(sql, set);

		for (NsRecordSet::iterator i = set.begin(); i != set.end(); i++){
			config_[(i->second)[key_field]] = (i->second)[val_field];
		}

	}

	Variant operator[](const AnsiString& sec_key){
		return config_[sec_key];
	}

	void Debug(){
		for (Configuration::iterator i = config_.begin(); i != config_.end(); i++){
			ShowMessage(i->first + "=" + i->second);
		}
	}
private:
	Configuration config_;
};

#endif  //NsConfig_H_
