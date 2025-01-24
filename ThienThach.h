#pragma once
#include"PhiThuyen.h"
#include"PhiThuyenHeThong.h"
#include"PhiThuyenPlayer.h"
#include<string>
using namespace std;
class ThienThach
{
protected:
	string MaSo;
	int SatThuong;
	string AmThanh;
public:
	enum Loai{cb, a, b};
	Loai pl = cb;
	ThienThach();
	~ThienThach() {}
	virtual void Set();
	virtual void Get() const;
	virtual void TanCong(PhiThuyen*& t) {};
};

