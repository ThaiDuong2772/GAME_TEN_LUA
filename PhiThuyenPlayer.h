#pragma once
#include"PhiThuyen.h"
class PhiThuyenPlayer : public PhiThuyen
{
protected:
	int SinhMenh_max;
	int HoiSinh;
public:
	PhiThuyenPlayer();
	~PhiThuyenPlayer() {}
	virtual void Set();
	virtual TenLua GetTenLua() const;
	virtual void SetSinhMenh(int x);
	void SelectTenLua(TenLua t);
	virtual void Get() const;
	virtual int GetSatThuong() const;
	virtual int GetSinhMenh() const;
};

