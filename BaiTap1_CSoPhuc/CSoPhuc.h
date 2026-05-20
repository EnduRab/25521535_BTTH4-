#pragma once
#include <iostream>

class CSoPhuc {
private:
	float thuc;
	float ao;
public:
	CSoPhuc(float = 0, float = 0);

	CSoPhuc operator+(const CSoPhuc&);
	CSoPhuc operator-(const CSoPhuc&);
	CSoPhuc operator*(const CSoPhuc&);
	CSoPhuc operator/(const CSoPhuc&);
	bool operator==(const CSoPhuc&);
	bool operator!=(const CSoPhuc&);

	friend std::istream& operator>>(std::istream&, CSoPhuc&);
	friend std::ostream& operator<<(std::ostream&, const CSoPhuc&);
};