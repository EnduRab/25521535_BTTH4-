#include "CDaThuc.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void cDaThuc::chuanHoa() {
	while (heSo.size() > 1 && heSo.back() == 0) {
		heSo.pop_back(); 
	}
}

cDaThuc::cDaThuc() {}
cDaThuc::cDaThuc(int n) {
	if (n < 0) n = 0;
	heSo.resize(n+1,0);
}
cDaThuc::cDaThuc(const vector<double>& hs) {
	heSo = hs;
}

double cDaThuc::tinhGiaTri(double x) const {
	double res = 0;
	for (int i = 0; i < heSo.size(); ++i) {
		res += heSo[i] * pow(x, i);
	}
	return res;
}

cDaThuc cDaThuc::daoHam() const {
	if (heSo.size() <= 1) return cDaThuc(0);

	cDaThuc dx;
	dx.heSo.resize(heSo.size() - 1);
	for (int i = 1; i < heSo.size(); ++i) {
		dx.heSo[i - 1] = i * heSo[i];
	}
	return dx;
}

cDaThuc cDaThuc::operator+(const cDaThuc& other) const {
	int maxBac = max(heSo.size(), other.heSo.size());
	cDaThuc res;
	res.heSo.resize(maxBac);
	for (int i = 0; i < maxBac; i++) {
		// kiem tra xem he so i hien tai co vuot qua so bac cua hai da thuc hay ko
		double heso1 = (i < heSo.size()) ? heSo[i] : 0;
		double heso2 = (i < other.heSo.size()) ? other.heSo[i] : 0;

		res.heSo[i] = heso1 + heso2;
	}
	res.chuanHoa();
	return res;
}

cDaThuc cDaThuc::operator-(const cDaThuc& other) const {
	int maxBac = max(heSo.size(), other.heSo.size());
	cDaThuc res;
	res.heSo.resize(maxBac);

	for (int i = 0; i < maxBac; i++) {
		// kiem tra xem he so i hien tai co vuot qua so bac cua hai da thuc hay ko
		double heso1 = (i < heSo.size()) ? heSo[i] : 0;
		double heso2 = (i < other.heSo.size()) ? other.heSo[i] : 0;

		res.heSo[i] = heso1 - heso2;
	}
	res.chuanHoa();
	return res;
}

cDaThuc cDaThuc::operator*(const cDaThuc& other) const {
	if (heSo.empty() || other.heSo.empty()) {
		return cDaThuc();
	}

	cDaThuc res;
	int sizeA = heSo.size();
	int sizeB = other.heSo.size();

	// Kích thước mảng kết quả = sizeA + sizeB - 1
	res.heSo.resize(sizeA + sizeB - 1, 0);

	// Nhân từng hạng tử của đa thức A với đa thức B
	for (int i = 0; i < sizeA; ++i) {
		for (int j = 0; j < sizeB; ++j) {
			res.heSo[i + j] += heSo[i] * other.heSo[j];
		}
	}
	res.chuanHoa();
	return res;
}

istream& operator>>(istream& in, cDaThuc& dt) {
	int n;
	do {
		cout << "Nhap bac cua da thuc: ";
		in >> n;
		if (n < 0) cout << "Bac cua da thuc phai >= 0\n";
	} while (n < 0);

	dt.heSo.resize(n+1);
	for (int i = dt.heSo.size() - 1; i >= 0; i--) {
		cout << "Nhap he so cho x^" << i << ": ";
		in >> dt.heSo[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const cDaThuc& dt) {
	if (dt.heSo.empty()) {
		out << "0";
		return out;
	}

	bool first = true; // kiem tra xem co phai he so dau tien

	// tim he so khac 0 de kiem tra xem da thuc co bang 0 hoan toan khong
	bool isZero = true;
	for (int i = dt.heSo.size() - 1; i >= 0; i--) {
		if (dt.heSo[i] != 0) {
			isZero = false;
			break;
		}
	}
	if (isZero) {
		out << "0";
		return out;
	}

	for (int i = dt.heSo.size() - 1; i >= 0; i--) {
		// he so = 0 thi bo qua
		if (dt.heSo[i] == 0) continue;

		// neu ko phai phan tu dau thi in dau cong hoac tru
		if (!first && dt.heSo[i] > 0) out << " + ";
		if (dt.heSo[i] < 0) {
			if (first) out << "-";
			else out << " - ";
		}

		// chi in he so neu no khac 1 hoac la so hang tu do
		double val = abs(dt.heSo[i]);
		if (val != 1 || i == 0) out << val;

		if (i > 0) out << "x";
		if (i > 1) out << "^" << i;

		first = false;
	}
	return out;
}