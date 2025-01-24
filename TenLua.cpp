#include "TenLua.h"
#include<iostream>

using namespace std;

TenLua::TenLua() {
	MaSo = Ten = "";
	SatThuong = SoLuotSD = 0;
}

void TenLua::Set() {
	cout << "Nhap Ma so ten lua: ";
	cin >> this->MaSo;
	cout << "Nhap ten cho ten lua: ";
	cin >> this->Ten;
	cout << "Nhap luong sat thuong: ";
	cin >> this->SatThuong;
	cout << "Nhap so luot su dung: ";
	cin >> this->SoLuotSD;
}

void TenLua::SetSL(int x) {
	this->SoLuotSD -= 1;
}

void TenLua::Get() const {
	cout << "Ma so ten lua: " << this->MaSo << endl;
	cout << "Ten cua ten lua: " << this->Ten << endl;
	cout << "Luong sat thuong: " << this->SatThuong << endl;
	cout << "So luot su dung: " << this->SoLuotSD << endl;
}

int TenLua::GetSL() const { return this->SoLuotSD; }

int TenLua::GetSatThuong() const { return this->SatThuong; }