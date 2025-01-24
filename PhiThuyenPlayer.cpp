#include "PhiThuyenPlayer.h"
#include<iostream>

using namespace std;

PhiThuyenPlayer::PhiThuyenPlayer() {
	PhiThuyen::PhiThuyen();
	SinhMenh_max = HoiSinh = 0;
	l = pl;
}

void PhiThuyenPlayer::Set() {
	PhiThuyen::Set();
	cout << "Nhap so mang cua nguoi choi: ";
	SinhMenh_max = this->SinhMenh;
	cin >> this->HoiSinh;
}

void PhiThuyenPlayer::SetSinhMenh(int x) {
	PhiThuyen::SetSinhMenh(x);
	if (this->HoiSinh <= 0 && this->SinhMenh <= 0) cout << "Nguoi choi bi ha guc!\n";
	if (this->SinhMenh <= 0) {
		this->HoiSinh -= 1;
		if (this->HoiSinh > 0) this->SinhMenh = SinhMenh_max;
	}
}

TenLua PhiThuyenPlayer::GetTenLua() const { return PhiThuyen::GetTenLua(); }

void PhiThuyenPlayer::SelectTenLua(TenLua t) { this->T = t; }

void PhiThuyenPlayer::Get() const {
	PhiThuyen::Get();
	cout << "So mang con lai: " << this->HoiSinh << endl;
	cout << "Thong tin ten lua:\n";
	this->T.Get();
}

int PhiThuyenPlayer::GetSatThuong() const { return PhiThuyen::GetSatThuong(); }

int PhiThuyenPlayer::GetSinhMenh() const { return PhiThuyen::GetSinhMenh(); }
