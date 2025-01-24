#pragma once
#include"ThienThach.h"
class ThienThachA : public ThienThach
{
public:
	ThienThachA();
	~ThienThachA() {}
	virtual void Set();
	virtual void Get() const;
	virtual void TanCong(PhiThuyen*& t);
};

