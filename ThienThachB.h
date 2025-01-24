#pragma once
#include"ThienThach.h"
class ThienThachB : public ThienThach
{
public:
	ThienThachB();
	~ThienThachB() {}
	virtual void Set();
	virtual void Get() const;
	virtual void TanCong(PhiThuyen*& t);
};

