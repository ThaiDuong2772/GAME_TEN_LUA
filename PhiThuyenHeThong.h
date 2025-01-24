#pragma once
#include"PhiThuyen.h"
class PhiThuyenHeThong : public PhiThuyen
{
public:
	PhiThuyenHeThong();
	~PhiThuyenHeThong() {}
	virtual void Set();
	virtual TenLua GetTenLua() const;
	virtual void SetSinhMenh(int x);
	virtual void Get() const;
	virtual int GetSatThuong() const;
	virtual int GetSinhMenh() const;
};

