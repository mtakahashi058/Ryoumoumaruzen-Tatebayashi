// ns_compatible.h: BCB6 �� XE(3 ��z��)���Ƃ̃��C�u�����݊����p�w�b�_

#ifndef NS_Compatible_H_
#define NS_Compatible_H_

#include <string>

#ifdef UNICODE

#define STRING      UnicodeString
#define STRING_POS  Pos
#define CSTR(x)     UnicodeString(x).c_str()

#else

#define STRING      AnsiString
#define STRING_POS  AnsiPos
#define CSTR(x)     x

#endif  //UNICODE

typedef std::basic_string<TCHAR> STDSTR;

#ifdef __CODEGEARC__

#define NS_TO_STRING    ToStr

#define ADONS           Data::Win::Adodb

#else

#define NS_TO_STRING    ToString

#define ADONS           Adodb

#endif  //__CODEGEARC__

#endif  //NS_Compatible_H_
