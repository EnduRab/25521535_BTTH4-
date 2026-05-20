#pragma once
#include <iostream>
#include <string>

class CTime {
private:
	int gio, phut, giay;
public:
	CTime(int = 0, int = 0, int = 0);
	bool thoiGian_hopLe();
	CTime operator+(int);
	CTime operator-(int);
	CTime& operator++();
	CTime& operator--();
	friend std::string format(int);
	friend std::istream& operator>>(std::istream&, CTime&);
	friend std::ostream& operator<<(std::ostream& out, const CTime&);
};