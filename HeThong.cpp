#include "HeThong.h"
#include<iostream>
#include<ctime>

using namespace std;

HeThong::~HeThong() {
	if (sl_tl > 0) delete[] dstl;
	for (int i = 0; i < sl_pt; i++) delete dspt[i];
	delete[] dspt;
	for (int i = 0; i < sl_tt; i++) delete dstt[i];
	delete[] dstt;
}

void HeThong::menu() {
	cout << "===================================================================\n";
	cout << "1. Cai dat doi tuong\n";
	cout << "2. Hien thi thong tin\n";
	cout << "3. Tran danh nguoi choi manh nhat vs phi thuyen he thong manh nhat\n";
	cout << "4. Mua thien thach\n";
	cout << "5. Thoat\n";
	cout << "==================================================================\n";
	int x; cin >> x;
	while (x != 5) {
		switch (x) {
		case 1:
		{
			system("cls");
			HeThong::Set();
			break;
		}
		case 2:
		{
			system("cls");
			HeThong::Get();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			HeThong::TanCongManhNhat();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			HeThong::MuaThienThach();
			system("pause");
		}
		default: break;
		}
		system("cls");
		cout << "===================================================================\n";
		cout << "1. Cai dat doi tuong\n";
		cout << "2. Hien thi thong tin\n";
		cout << "3. Tran danh nguoi choi manh nhat vs phi thuyen he thong manh nhat\n";
		cout << "4. Mua thien thach\n";
		cout << "5. Thoat\n";
		cout << "==================================================================\n";
		cin >> x;
	}
}

void HeThong::Set() {
	cout << "Nhap so luong ten lua: ";
	cin >> this->sl_tl;
	dstl = new TenLua[sl_tl];
	for (int i = 0; i < this->sl_tl; i++) dstl[i].Set();
	cout << "Nhap so luong Phi thuyen: ";
	cin >> this->sl_pt;
	dspt = new PhiThuyen*[sl_pt];
	int temp; 
	srand(time(NULL));
	for (int i = 0; i < this->sl_pt; i++) {
		cout << "Chon loai phi thuyen:\n";
		cout << "1. Nguoi choi\t 2. He thong\n";
		cin >> temp;
		switch (temp)
		{
		case 1: 
		{
			dspt[i] = new PhiThuyenPlayer;
			dspt[i]->Set();
			
			int index = rand() % this->sl_tl;

			cout << "Nhat duoc ten lua thu " << index + 1 << " trong danh sach.\n";
			((PhiThuyenPlayer*)dspt[i])->SelectTenLua(dstl[index]);
			break;
		}
		case 2:
		{
			dspt[i] = new PhiThuyenHeThong;
			dspt[i]->Set();
			break;
		}
		default:
			cout << "Moi nhap lai!\n";
			i--;
			break;
		}
	}
	cout << "Nhap so luong thien thach: ";
	cin >> sl_tt;
	dstt = new ThienThach*[sl_tt];
	for (int i = 0; i < sl_tt; i++) {
		cout << "Chon loai thien thach:\n";
		cout << "1. Thien thach alpha\t 2. Thien thach beta\n";
		cin >> temp;
		switch (temp)
		{
		case 1:
		{
			dstt[i] = new ThienThachA;
			dstt[i]->Set();
			break;
		}
		case 2:
		{
			dstt[i] = new ThienThachB;
			dstt[i]->Set();
			break;
		}
		default:
			cout << "Moi nhap lai!\n";
			i--;
			break;
		}
	}
}

void HeThong::Get() const {
	cout << "\nDanh sach ten lua:\n";
	int cnt = 1;
	for (int i = 0; i < this->sl_tl; i++) 
	{
		cout << "=====================================================\n";
		cout << "Ten lua thu " << cnt++ << ":\n";
		dstl[i].Get();
	}
	cout << "\nDanh sach phi thuyen:\n";
	cnt = 1;
	for (int i = 0; i < this->sl_pt; i++)
	{
		cout << "=====================================================\n";
		switch (dspt[i]->l)
		{
		case PhiThuyen::pl:
		{
			cout << cnt++ << ". Phi thuyen nguoi choi:\n";
			dspt[i]->Get();
			break;
		}
		case PhiThuyen::sys:
		{
			cout << cnt++ << ". Phi thuyen he thong:\n";
			dspt[i]->Get();
			break;
		}
		default:
			cout << "Errors!\n";
			break;
		}
	}
	cout << "\nDanh sach thien thach:\n";
	cnt = 1;
	for (int i = 0; i < this->sl_tt; i++)
	{
		cout << "=====================================================\n";
		switch (dstt[i]->pl)
		{
		case ThienThach::a:
		{
			cout << cnt++ << ". Thien thach alpha:\n";
			dstt[i]->Get();
			break;
		}
		case ThienThach::b:
		{
			cout << cnt++ << ". Thien thach beta:\n";
			dstt[i]->Get();
			break;
		}
		default:
			cout << "Errors!\n";
			break;
		}
	}
}

PhiThuyenPlayer HeThong::GetPlayerManhNhat() const {
	int hp = 0;
	int value = 0;
	int index;
	for (int i = 0; i < this->sl_pt; i++) {
		if (dspt[i]->l == PhiThuyen::pl) {
			if (value < dspt[i]->GetSatThuong() || (value == dspt[i]->GetSatThuong() && hp < dspt[i]->GetSinhMenh())) {
				value = dspt[i]->GetSatThuong();
				hp = dspt[i]->GetSinhMenh();
				index = i;
			}
		}
	}
	return *((PhiThuyenPlayer*)dspt[index]);
}

PhiThuyenHeThong HeThong::GetHeThongManhNhat() const {
	int hp = 0;
	int value = 0;
	int index;
	for (int i = 0; i < this->sl_pt; i++) {
		if (dspt[i]->l == PhiThuyen::sys) {
			if (value < dspt[i]->GetSatThuong() || (value == dspt[i]->GetSatThuong() && hp < dspt[i]->GetSinhMenh())) {
				value = dspt[i]->GetSatThuong();
				hp = dspt[i]->GetSinhMenh();
				index = i;
			}
		}
	}
	return *((PhiThuyenHeThong*)dspt[index]);
}

void HeThong::TanCongManhNhat() {
	TenLua t1, t2;
	PhiThuyenPlayer p1 = this->GetPlayerManhNhat();
	t1 = p1.GetTenLua();
	PhiThuyenHeThong p2 = this->GetHeThongManhNhat();
	t2 = p2.GetTenLua();
	p1.Get();
	p2.Get();
	cout << "\nTran dau bat dau!\n";
	cout << "========================================================\n";
	while (p1.GetSinhMenh() > 0 && p2.GetSinhMenh() > 0 && (t1.GetSL() || t2.GetSL())) {
		if (t2.GetSL() > 0) {
			cout << "Nguoi choi nhan " << p2.GetSatThuong() << " sat thuong!\n";
			p1.SetSinhMenh(p2.GetSatThuong());
		}
		t2.SetSL(1);
		if (t1.GetSL() > 0) {
			cout << "Phi thuyen he thong nhan " << p1.GetSatThuong() << " sat thuong!\n";
			p2.SetSinhMenh(p1.GetSatThuong());
		}
		t1.SetSL(1);
		cout << "Sinh menh nguoi choi: " << p1.GetSinhMenh() << endl;
		cout << "SInh menh phi thuyen he thong: " << p2.GetSinhMenh() << endl;
	}
	cout << "========================================================\n";
	if ((p1.GetSinhMenh() <= 0 && p2.GetSinhMenh() <= 0) || (p1.GetSinhMenh() > 0 && p2.GetSinhMenh() > 0)) cout << "Tran chien hoa!\n";
	else if (p2.GetSinhMenh() <= 0) cout << "Player won!\n";
	else if (p1.GetSinhMenh() <= 0) cout << "Player defeated!\n";
}

void HeThong::MuaThienThach() {
	cout << "Danh sach phi thuyen:\n";
	int cnt = 1;
	for (int i = 0; i < this->sl_pt; i++)
	{
		switch (dspt[i]->l)
		{
		case PhiThuyen::pl:
		{
			cout << cnt++ << ". Phi thuyen nguoi choi:\n";
			dspt[i]->Get();
			break;
		}
		case PhiThuyen::sys:
		{
			cout << cnt++ << ". Phi thuyen he thong:\n";
			dspt[i]->Get();
			break;
		}
		default:
			cout << "Errors!\n";
			break;
		}
	}
	cout << "Chon Phi Thuyen dinh phai mua thien thach: ";
	int index; cin >> index;
	index--;
	for (int i = 0; i < this->sl_tt; i++) {
		dstt[i]->TanCong(dspt[index]);
	}
	if (dspt[index]->GetSinhMenh() > 0) dspt[index]->Get();
}
