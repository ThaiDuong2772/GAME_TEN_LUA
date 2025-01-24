#pragma once
#include"TenLua.h"
#include"PhiThuyenPlayer.h"
#include"PhiThuyenHeThong.h"
#include"ThienThachA.h"
#include"ThienThachB.h"
class HeThong : public TenLua, public PhiThuyen, public ThienThach
{
private:
	int sl_tl, sl_pt, sl_tt;
	TenLua* dstl;
	PhiThuyen** dspt;
	ThienThach** dstt;
public:
	HeThong(int tl = 0, int pt = 0, int tt = 0) : sl_tl(tl), sl_pt(pt), sl_tt(tt) {
		dstl = NULL;
		dspt = nullptr;
		dstt = nullptr;
	}
	~HeThong();
	void menu();
	void Set();
	void Get() const;
	PhiThuyenPlayer GetPlayerManhNhat() const;
	PhiThuyenHeThong GetHeThongManhNhat() const;
	void TanCongManhNhat();
	void MuaThienThach();
};

