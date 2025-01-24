#include "ThienThachA.h"
#include<iostream>

using namespace std;

ThienThachA::ThienThachA() : ThienThach() {
	pl = a;
}

void ThienThachA::Set() {
	ThienThach::Set();
	this->AmThanh = "Alpha Alpha Bum!";
	this->SatThuong = 2;
}

void ThienThachA::Get() const {
	ThienThach::Get();
	cout << "Sat thuong: " << this->SatThuong << endl;
	cout << "Am thanh no: " << this->AmThanh << endl;
}

void ThienThachA::TanCong(PhiThuyen*& t) {
	cout << "Am thanh no: " << this->AmThanh << endl;
	cout << "Phi thuyen dinh " << this->SatThuong << " sat thuong!\n";
	t->SetSinhMenh(this->SatThuong);
}
 