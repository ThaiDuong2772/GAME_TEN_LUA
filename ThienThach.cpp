#include "ThienThach.h"
#include<iostream>

using namespace std;

ThienThach::ThienThach() {
	MaSo = AmThanh = "";
	SatThuong = 0;
}

void ThienThach::Set() {
	cout << "Nhap Ma so thien thach: ";
	cin >> this->MaSo;
}

void ThienThach::Get() const {
	cout << this->MaSo << endl;;
}
