#include "CDate.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void tinhLaiSuat() {

	cout << fixed << setprecision(0);

	CDate ngayGui, ngayRut;
	double tienGui, laiSuat;
	cout << "--- NHAP NGAY BAT DAU GUI NGAN HANG ---\n";
	cin >> ngayGui;
	cout << "Nhap so tien da gui ngan hang: ";
	cin >> tienGui;
	cout << "Nhap lai suat cua ngan hang (%/nam): ";
	cin >> laiSuat;
	cout << "--- NHAP NGAY RUT TIEN ---\n";
	do {
		cin >> ngayRut;
		if (ngayGui > ngayRut) cout << "Vui long nhap ngay rut sau ngay gui\n";
	} while (ngayGui > ngayRut);
	
	long long khoangCach = ngayGui.tinhKhoangCach(ngayRut);
	double soTienLai = tienGui * (laiSuat / 100) * (khoangCach / 365.0);
	cout << "So tien lai sau khi gui ngan hang " << khoangCach << " ngay la: " << soTienLai << endl;
}

int main() {

	CDate d1, d2;
	cout << "===== NHAP NGAY/THANG/NAM =====\n";
	cin >> d1;
	cout << "===== NGAY/THANG/NAM THU DA NHAP LA =====\n";
	cout << d1 << endl;

	cout << "===== CONG 365 NGAY =====\n";
	cout << d1 + 365 << endl;
	cout << "===== TRU 365 NGAY =====\n";
	cout << d1 - 365 << endl;
	cout << "===== TONG TU ++ =====\n";
	d1++;
	cout << d1 << endl;
	cout << "===== TOAN TU -- =====\n";
	d1--;
	cout << d1 << endl;

	cout << "===== BAI TOAN TINH LAI SUAT NGAN HANG =====\n";
	tinhLaiSuat();
    return 0;
}