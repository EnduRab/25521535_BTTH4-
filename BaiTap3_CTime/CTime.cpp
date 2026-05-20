#include "CTime.h"
#include <iostream>
#include <string>

using namespace std;

bool CTime::thoiGian_hopLe() {
	if (gio < 0 || phut < 0 || giay < 0) return false;
	if (gio >= 24 || phut >= 60 || giay >= 60) return false;
	return true;
}

string format(int s) {
	if (s >= 10) return to_string(s);
	else return "0" + to_string(s);
}

CTime::CTime(int h, int m, int s) : gio(h), phut(m), giay(s) {}

CTime CTime::operator+(int sec) {
	// Lay tong giay + giay them vao
	long long tongGiay = (long long)gio * 3600 + phut * 60 + giay;
	tongGiay += sec;

	// chia lay du cho so giay trong 1 ngay de thoi gian khong vuot qua 24h
	tongGiay %= 86400;
	if (tongGiay < 0) tongGiay += 86400;

	// Chuyen doi tu giay ve lai gio/phut/giay
	int h = tongGiay / 3600;
	int m = (tongGiay % 3600) / 60;
	int s = tongGiay % 60;

	return CTime(h, m, s);
}

CTime CTime::operator-(int sec) {
	// cong cho (-sec)
	return (*this + (-sec));
}

CTime& CTime::operator++() {
	*this = *this + 1;
	return *this;
}

CTime& CTime::operator--() {
	*this = *this - 1;
	return *this;
}

istream& operator>>(istream& in, CTime& time) {
	do {
		cout << "Nhap gio: "; in >> time.gio;
		cout << "Nhap phut: "; in >> time.phut;
		cout << "Nhap giay: "; in >> time.giay;
		if (time.thoiGian_hopLe() == false) cout << "Thoi gian khong hop le, vui long nhap lai!\n";
	} while (time.thoiGian_hopLe() == false);
	return in;
}

ostream& operator<<(ostream& out, const CTime& time) {
	string timeStr = format(time.gio) + ":" + format(time.phut) + ":" + format(time.giay);
	out << timeStr << endl;
	return out;
}

