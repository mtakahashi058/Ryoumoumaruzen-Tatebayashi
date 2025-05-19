/**
 * utility.h: ユーティリティクラス、関数オブジェクトヘッダー
 *
 *				@author		ack(akio)
 *				@history	2002/05/15 add ToUpper/ToLower, StrCompI
 *						2002/07/05 add trimRight/trimLeft
 *						2002/09/10 add toString/fromString
 *						2002/09/10 add toString/fromString
 */

#ifndef	_Utility_H_
#define	_Utility_H_

#include <string>
#include <locale>
//#include <cctype>	// iscntrl
#include <cwctype>	// iswcntrl
#include <algorithm>
#include <functional>
#include <sstream>

// ackl: original namespace
namespace ackl{

	// trimLeft: 先頭空白文字除去のための関数
	template <class charT>
	std::basic_string<charT, std::char_traits<charT>, std::allocator<charT> >
		trimLeft(std::basic_string<charT, std::char_traits<charT>, std::allocator<charT> > arg){
		std::basic_string<charT, std::char_traits<charT>, std::allocator<charT> > result;
		std::replace_if(arg.begin(), arg.end(), std::iswcntrl, ' ');
		std::basic_string<charT, std::char_traits<charT>, std::allocator<charT> >::size_type n = arg.find_first_not_of(' ');
		if (n != std::basic_string<charT, std::char_traits<charT>, std::allocator<charT> >::npos)
			result = arg.substr(n);
		return result;
	}

	// trimRight: 末尾空白文字除去のための関数
	template <class charT>
	std::basic_string<charT, std::char_traits<charT>, std::allocator<charT> >
		trimRight(std::basic_string<charT, std::char_traits<charT>, std::allocator<charT> > arg){
		std::basic_string<charT, std::char_traits<charT>, std::allocator<charT> > result;
		std::replace_if(arg.begin(), arg.end(), std::iswcntrl, ' ');
		std::basic_string<charT, std::char_traits<charT>, std::allocator<charT> >::size_type n = arg.find_last_not_of(' ');
		if (n != std::basic_string<charT, std::char_traits<charT>, std::allocator<charT> >::npos)
			result = arg.substr(0, n + 1);
		return result;
	}
	/**
	 * is(w)cntrlについての補足
	 *	未確認ではあるが、処理系(g++)によってはiswcntrlがサポートされていないようだ。
	 *	この場合、iscntrlを使用するべきなのだが、処理系によってうまく動かなかったり、
	 *	localeの設定をしなければならなかったりする。
	 *	したがってここではiswcntrlを使用した。
	 *	もしiswcntrlが使用できない場合や、正常な動作が出来ない場合は
	 *	適宜書き換えが必要となる。
	 */
	/**
	 * trimRight/trimLeft sample code
	 *	std::wstring ws = L"  hoho hoho!  ";
	 *	std::wstring s1, s2;
	 *	// 末尾空白削除
	 *	s1 = ackl::trimRight(ws);
	 *	// 先頭空白削除
	 *	s2 = ackl::trimLeft(ws);
	 *
	 */

	// ToUpper: 大文字変換のための関数オブジェクト
	template <class charT>
	class toUpper : public std::unary_function<charT, void>{
	public:
		void operator()(const charT& arg) const
			{arg = std::toupper(arg);}
	};
	// ToLower: 小文字変換のための関数オブジェクト
	template <class charT>
	class toLower : public std::unary_function<charT, void>{
	public:
		void operator()(const charT& arg) const
			{arg = std::tolower(arg);}
	};
	/**
	 * toUpper/toLower sample code
	 *	std::wstring foo = "SampleText";
	 *	// 大文字化
	 *	std::for_each(foo.begin(), foo.end(), ackl::toUpper<wchar_t>());
	 *	// 小文字化
	 *	std::for_each(foo.begin(), foo.end(), ackl::toLower<wchar_t>());
	 */

	// StrCompI: 大文字小文字を無視した比較のための関数オブジェクト
	template <class charT>
	class StrCompI : private std::binary_function<charT, charT, bool>{
	public:
		bool operator()(const charT& x, const charT& y) const {
			return std::toupper(x) == std::toupper(y);
		}
	};
	/**
	 * StrCompI sample code
	 *	bool isequal =
	 *	std::equal(fuga.begin(), fuga.end(), fuga2.begin(), ackl::StrCompI<wchar_t>());
	 */

	// toString: テンプレートを利用した文字列への変換関数
	template <class T>
	std::string toString(const T& val){
		std::ostringstream os;
		os << val;
		return os.str();
	}
	template <class T>
	std::wstring toWString(const T& val){
		std::wostringstream os;
		os << val;
		return os.str();
	}
	/**
	 * toString sample code
	 *	std::string foo(ackl::toString<int>(5));
	 *	std::wstring bar(ackl::toWString<int>(5));
	 */

	// fromString: テンプレートを利用した文字列からの変換関数
	template <class T>
	T fromString(const std::string& src){
	 	T result;
	 	std::istringstream is(src);
	 	is >> result;
	 	return result;
	}
	template <class T>
	T fromWString(const std::wstring& src){
	 	T result;
	 	std::wistringstream is(src);
	 	is >> result;
	 	return result;
	}
	/**
	 * fromString sample code
	 *	return ackl::fromString<double>("2.15");
	 *	return ackl::fromWString<double>("2.15");
	 */

	// constを外すカラクリ
	template<class T> inline T & disconst (const T &Value) {
		return const_cast<T&>(Value);
	}
	/**
	 * disconst sample code
	 * 	disconst(Instance).notConstMethod();
	 */

};

#endif	//_Utility_H_
