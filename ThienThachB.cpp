#include "ThienThachB.h"
#include<iostream>

using namespace std;

ThienThachB::ThienThachB() : ThienThach() {
	pl = b;
}

void ThienThachB::Set() {
	ThienThach::Set();
	this->AmThanh = "Beta Beta Bum!";
	this->SatThuong = 3;
}

void ThienThachB::Get() const {
	ThienThach::Get();
	cout << "Sat thuong: " << this->SatThuong << endl;
	cout << "Am thanh no: " << this->AmThanh << endl;
}

void ThienThachB::TanCong(PhiThuyen*& t) {
	cout << "Am thanh no: " << this->AmThanh << endl;
	cout << "Phi thuyen dinh " << this->SatThuong << " sat thuong!\n";
	t->SetSinhMenh(this->SatThuong);
}
