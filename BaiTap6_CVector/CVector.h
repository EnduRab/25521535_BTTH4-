#pragma once
#include <iostream>
#include <vector>

using namespace std;

class CVector {
private:
	vector<double> data;
public:

	CVector();
	CVector(const vector<double>&);
	CVector(int);

	int getDim() const;

	double& operator[](int i);              // ghi
	double  operator[](int i) const;        // doc
	
	CVector operator+(const CVector&) const;
	CVector operator-(const CVector&) const;

	// Tich vo huong 2 vector
	double operator*(const CVector&) const;

	// Tich cua mot vector voi 1 so
	CVector operator*(const double) const;


	friend istream& operator>>(istream&, CVector&);
	friend ostream& operator<<(ostream&, const CVector&);

};