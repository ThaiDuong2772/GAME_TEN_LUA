#pragma once
#include"TenLua.h"
#include<string>
using namespace std;
class PhiThuyen
{
protected:
	string MaSo, Ten;
	int SinhMenh;
	TenLua T;
public:
	enum Loai {cb, pl, sys};
	Loai l = cb;
	PhiThuyen();
	~PhiThuyen() {}
	virtual void Set();
	virtual TenLua GetTenLua() const;
	virtual void SetSinhMenh(int x);
	virtual void Get() const;
	virtual int GetSatThuong() const;
	virtual int GetSinhMenh() const;
};

