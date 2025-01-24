#include "PhiThuyen.h"
#include<iostream>

using namespace std;

PhiThuyen::PhiThuyen() {
	MaSo = Ten = "";
	SinhMenh = 0;
	T;
}

void PhiThuyen::Set() {
	cout << "Nhap Ma so Phi thuyen: ";
	cin >> this->MaSo;
	cout << "Nhap ten cho Phi thuyen: ";
	cin >> this->Ten;
	cout << "Nhap Luong sinh menh: ";
	cin >> this->SinhMenh;
}

TenLua PhiThuyen::GetTenLua() const { return T; }

void PhiThuyen::SetSinhMenh(int x) {
	this->SinhMenh -= x;
}

void PhiThuyen::Get() const {
	cout << "Ma so Phi thuyen: " << this->MaSo << endl;
	cout << "Ten cua Phi thuyen: " << this->Ten << endl;
	cout << "Luong sinh menh: " << this->SinhMenh << endl;
}

int PhiThuyen::GetSatThuong() const { return this->T.GetSatThuong(); }

int PhiThuyen::GetSinhMenh() const { return this->SinhMenh; }