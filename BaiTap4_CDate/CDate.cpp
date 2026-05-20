#include "CDate.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ngayTrongThang(int thang,int nam) {
	int ngay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// neu nam nhuan thi thang 2 co 29 ngay
	if (((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))) {
		ngay[2] = 29;
	}
	return ngay[thang];
}

bool ngayHopLe(int ngay, int thang, int nam) {
	if (ngay <= 0 || thang <= 0 || nam <= 0 || thang > 12 || ngay > ngayTrongThang(thang, nam)) return false;
	return true;
}

CDate::CDate(int ng,int th,int n): ngay(ng),thang(th),nam(n) {}

CDate CDate::operator+(int ngayThem) {
	CDate res = *this;
	res.ngay += ngayThem;
	while (res.ngay > ngayTrongThang(res.thang, res.nam)) {
		res.ngay -= ngayTrongThang(res.thang, res.nam);
		res.thang++;
		if (res.thang > 12) {
			res.thang = 1;
			res.nam++;
		}
	}
	return res;
}

CDate CDate::operator-(int ngayBot) {
	CDate res = *this;
	res.ngay -= ngayBot;
	while (res.ngay <= 0) {
		res.thang--;
		if (res.thang < 1) {
			res.thang = 12;
			res.nam--;
		}
		res.ngay += ngayTrongThang(res.thang, res.nam);
	}
	return res;
}

CDate CDate::operator++(int) {
	CDate temp = *this;
	*this = *this + 1;
	return temp;
}

CDate CDate::operator--(int) {
	CDate temp = *this;
	*this = *this - 1;
	return temp;
}

CDate& CDate::operator++() {
	*this = *this + 1;
	return *this;
}

CDate& CDate::operator--() {
	*this = *this - 1;
	return *this;
}

istream& operator>>(istream& in, CDate& date) {
	do {
		cout << "Nhap ngay: "; in >> date.ngay;
		cout << "Nhap thang: "; in >> date.thang;
		cout << "Nhap nam: "; in >> date.nam;
		if (!ngayHopLe(date.ngay, date.thang, date.nam))
			cout << "Ngay thang nam khong hop le, vui long nhap lai\n";
	} while (!ngayHopLe(date.ngay,date.thang,date.nam));
	return in;
}

ostream& operator<<(ostream& out, const CDate& date) {
	string dateStr = "";
	if (date.ngay < 10) dateStr += "0";
	dateStr += to_string(date.ngay) + "/";
	if (date.thang < 10) dateStr += "0";
	dateStr += to_string(date.thang) + "/";
	dateStr += to_string(date.nam);
	out << dateStr;
	return out;
}

long long CDate::tongNgay() {
	long long tongNgay = ngay;

	// tong so ngay cua nam hien tai
	for (int i = 1; i < thang; ++i) {
		tongNgay += ngayTrongThang(i, nam);
	}

	// Tong cac so ngay trong cua cac nam truoc do
	for (int i = 1; i < nam; ++i) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
			tongNgay += 366; // nam nhuan
		}
		else {
			tongNgay += 365; // nam thuong
		}
	}

	return tongNgay;
}

long long CDate::tinhKhoangCach(CDate other) {
	long long ngay1 = this->tongNgay();
	long long ngay2 = other.tongNgay();
	return abs(ngay1 - ngay2);
}	

bool CDate::operator>(CDate other) {
	if (nam != other.nam)
		return nam > other.nam;
	if (thang != other.thang)
		return thang > other.thang;
	return ngay > other.ngay;
}