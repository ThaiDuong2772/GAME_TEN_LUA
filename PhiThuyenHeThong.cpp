#include "PhiThuyenHeThong.h"
#include<iostream>

using namespace std;

PhiThuyenHeThong::PhiThuyenHeThong() {
	PhiThuyen::PhiThuyen();
	l = sys;
}

void PhiThuyenHeThong::Set() {
	PhiThuyen::Set();
	this->T.Set();
}

TenLua PhiThuyenHeThong::GetTenLua() const { return PhiThuyen::GetTenLua(); }

void PhiThuyenHeThong::SetSinhMenh(int x) {
	PhiThuyen::SetSinhMenh(x);
	if (this->SinhMenh <= 0) cout << "Phi thuyen bi ha!\n";
}

void PhiThuyenHeThong::Get() const {
	PhiThuyen::Get();
	cout << "Thong tin ten lua:\n";
	this->T.Get();
}

int PhiThuyenHeThong::GetSatThuong() const { return PhiThuyen::GetSatThuong(); }

int PhiThuyenHeThong::GetSinhMenh() const { return PhiThuyen::GetSinhMenh(); }