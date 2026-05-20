#pragma once

#include <iostream>
#include <vector>
#include "CVector.h"

using namespace std;

class CMatrix {
private:
	int hang;
	int cot;
	vector<vector<double>> data;
public:

	CMatrix(int = 0, int = 0);

	CMatrix operator+(const CMatrix&) const;
	CMatrix operator-(const CMatrix&) const;

	double& operator()(int i, int j); // ghi
	double  operator()(int i, int j) const; // doc

	CMatrix operator*(const double) const;   // nhan ma tran voi he so k
	CMatrix operator*(const CMatrix&) const; // nhan ma tran voi ma tran
	CVector operator*(const CVector&) const; // nhan ma tran voi vector

	CMatrix transpose() const; // Ma tran chuyen vi

	friend istream& operator>>(istream&, CMatrix&);
	friend ostream& operator<<(ostream&, const CMatrix&);
};