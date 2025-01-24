#pragma once
#include<string>
using namespace std;
class TenLua
{
protected:
	string MaSo;
	string Ten;
	int SatThuong;
	int SoLuotSD;
public:
	TenLua();
	~TenLua() {};
	void Set();
	void SetSL(int x);
	void Get() const;
	int GetSL() const;
	int GetSatThuong() const;
};

