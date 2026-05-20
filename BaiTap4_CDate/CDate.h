#pragma once
#include <iostream>

class CDate {
private:
	int ngay, thang, nam;
public:
	CDate(int = 1, int = 1, int = 1);
	CDate operator+(int);
	CDate operator-(int);

	// postfix
	CDate operator++(int);
	CDate operator--(int);

	// prefix
	CDate& operator++();
	CDate& operator--();

	bool operator>(CDate);
	long long tongNgay();
	long long tinhKhoangCach(CDate);

	friend std::istream& operator>>(std::istream&, CDate&);
	friend std::ostream& operator<<(std::ostream&, const CDate&);
};