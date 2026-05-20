#include "CPhanSo.h"

int UCLN(int a, int b) {
	a = abs(a);
	if (b == 0) return a;
	return UCLN(b, a % b);
}

void CPhanSo::RutGon() {
	int uoc = UCLN(tu, mau);
	tu /= uoc;
	mau /= uoc;

	if (mau < 0) {
		tu = -tu;
		mau = -mau;
	}
}

CPhanSo::CPhanSo(int t, int m) : tu(t), mau(m) {
	RutGon();
}

CPhanSo CPhanSo::operator+(const CPhanSo& other) {
	return CPhanSo(tu * other.mau + other.tu * mau, mau * other.mau);
}

CPhanSo CPhanSo::operator-(const CPhanSo& other) {
	return CPhanSo(tu * other.mau - other.tu * mau, mau * other.mau);
}

CPhanSo CPhanSo::operator*(const CPhanSo& other) {
	return CPhanSo(tu * other.tu, mau * other.mau);
}

CPhanSo CPhanSo::operator/(const CPhanSo& other) {
	return CPhanSo(tu * other.mau, mau * other.tu);
}

bool CPhanSo::operator==(const CPhanSo& other) const {
	return (tu == other.tu && mau == other.mau);
}

bool CPhanSo::operator>(const CPhanSo& other) {
	return (tu * other.mau) > (other.tu * mau);
}

bool CPhanSo::operator<(const CPhanSo& other) {
	return (tu * other.mau) < (other.tu * mau);
}

std::istream& operator>>(std::istream& in, CPhanSo& ps) {
	do {
		std::cout << "Nhap tu: ";  in >> ps.tu;
		std::cout << "Nhap mau: "; in >> ps.mau;
		if (ps.mau == 0)
			std::cout << "Mau so khong duoc bang 0, nhap lai!\n";
	} while (ps.mau == 0);
	ps.RutGon();
	return in;
}

std::ostream& operator<<(std::ostream& out, const CPhanSo& ps) {
	out << ps.tu;
	if(ps.mau != 1) out << "/" << ps.mau;
	return out;
}

 