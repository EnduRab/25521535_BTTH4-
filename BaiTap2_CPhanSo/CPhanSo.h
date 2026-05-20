#pragma once
#include <iostream>

class CPhanSo {
private:
	int tu;
	int mau;
	void RutGon();
public:
	CPhanSo(int = 0, int = 1);

	CPhanSo operator+(const CPhanSo&);
	CPhanSo operator-(const CPhanSo&);
	CPhanSo operator*(const CPhanSo&);
	CPhanSo operator/(const CPhanSo&);
	bool operator==(const CPhanSo&) const;
	bool operator>(const CPhanSo&);
	bool operator<(const CPhanSo&);

	friend std::istream& operator>>(std::istream&, CPhanSo&);
	friend std::ostream& operator<<(std::ostream&, const CPhanSo&);
};