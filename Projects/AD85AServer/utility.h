/**
 * utility.h: ���[�e�B���e�B�N���X�A�֐��I�u�W�F�N�g�w�b�_�[
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

	// trimLeft: �擪�󔒕��������̂��߂̊֐�
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

	// trimRight: �����󔒕��������̂��߂̊֐�
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
	 * is(w)cntrl�ɂ��Ă̕⑫
	 *	���m�F�ł͂��邪�A�����n(g++)�ɂ���Ă�iswcntrl���T�|�[�g����Ă��Ȃ��悤���B
	 *	���̏ꍇ�Aiscntrl���g�p����ׂ��Ȃ̂����A�����n�ɂ���Ă��܂������Ȃ�������A
	 *	locale�̐ݒ�����Ȃ���΂Ȃ�Ȃ������肷��B
	 *	���������Ă����ł�iswcntrl���g�p�����B
	 *	����iswcntrl���g�p�ł��Ȃ��ꍇ��A����ȓ��삪�o���Ȃ��ꍇ��
	 *	�K�X�����������K�v�ƂȂ�B
	 */
	/**
	 * trimRight/trimLeft sample code
	 *	std::wstring ws = L"  hoho hoho!  ";
	 *	std::wstring s1, s2;
	 *	// �����󔒍폜
	 *	s1 = ackl::trimRight(ws);
	 *	// �擪�󔒍폜
	 *	s2 = ackl::trimLeft(ws);
	 *
	 */

	// ToUpper: �啶���ϊ��̂��߂̊֐��I�u�W�F�N�g
	template <class charT>
	class toUpper : public std::unary_function<charT, void>{
	public:
		void operator()(const charT& arg) const
			{arg = std::toupper(arg);}
	};
	// ToLower: �������ϊ��̂��߂̊֐��I�u�W�F�N�g
	template <class charT>
	class toLower : public std::unary_function<charT, void>{
	public:
		void operator()(const charT& arg) const
			{arg = std::tolower(arg);}
	};
	/**
	 * toUpper/toLower sample code
	 *	std::wstring foo = "SampleText";
	 *	// �啶����
	 *	std::for_each(foo.begin(), foo.end(), ackl::toUpper<wchar_t>());
	 *	// ��������
	 *	std::for_each(foo.begin(), foo.end(), ackl::toLower<wchar_t>());
	 */

	// StrCompI: �啶���������𖳎�������r�̂��߂̊֐��I�u�W�F�N�g
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

	// toString: �e���v���[�g�𗘗p����������ւ̕ϊ��֐�
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

	// fromString: �e���v���[�g�𗘗p���������񂩂�̕ϊ��֐�
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

	// const���O���J���N��
	template<class T> inline T & disconst (const T &Value) {
		return const_cast<T&>(Value);
	}
	/**
	 * disconst sample code
	 * 	disconst(Instance).notConstMethod();
	 */

};

#endif	//_Utility_H_
