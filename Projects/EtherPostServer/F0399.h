// F0399.h: エフテック社製 7セグ表示器 F0399 制御クラスヘッダ

#ifndef F0399_H_
#define F0399_H_

#define F0399_COMM_DEF      ("9600,N,8,1")

#include "ocomm.h"

class F0399 {
public:
    F0399(){}
    virtual ~F0399();

    bool Initialize(int port, LPCSTR def = F0399_COMM_DEF);
    void Close();

    bool IsActive();

    void Display(LPCSTR text);
    
protected:
    ackl::OverlappedComm comm_;
	OVERLAPPED o_write_;

private:
    void operator=(const F0399& src){}
    F0399(const F0399& src){}
};

#endif  //F0399_H_
 