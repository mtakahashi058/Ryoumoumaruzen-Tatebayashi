#ifndef NsVar_H_
#define NsVar_H_

/** Variant Helper Function **/
int ToInt(const Variant& var){
    if (var.IsNull() || var.IsEmpty())  return 0;

    AnsiString v = var;
    return v.ToIntDef(0);
}

Currency ToCurrency(const Variant& var){
    if (var.IsNull() || var.IsEmpty())  return 0;

    AnsiString v = var;
    return StrToCurrDef(v, 0);
}

AnsiString ToString(const Variant& var){
    if (var.IsNull() || var.IsEmpty())  return "";
    return var;
}

bool ToBit(const Variant& var){
    if (var.IsNull() || var.IsEmpty())  return false;
    return var;
}

int ToBit(bool b){
    return b ? 1 : 0;
}

Variant ToVariant(const AnsiString& str){
    if (str.IsEmpty())
        return Variant();
    else
        return Variant(str);
}

bool IsNull(const Variant& var){
    if (var.IsNull() || var.IsEmpty())  return true;
    return false;
}

#endif  //NsVar_H_
