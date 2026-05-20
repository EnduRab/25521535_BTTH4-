#include "CVector.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

CVector::CVector() {}
CVector::CVector(const vector<double>& v) : data(v) {}
CVector::CVector(int n) {
	data.resize(n);
}

int CVector::getDim() const {
	return (int)data.size();
}

double& CVector::operator[](int i) {
	if (i < 0 || i >= getDim())
		throw out_of_range("Chi so vuot ngoai pham vi!");
	return data[i];
}

double CVector::operator[](int i) const {
	if (i < 0 || i >= getDim())
		throw out_of_range("Chi so vuot ngoai pham vi!");
	return data[i];
}

CVector CVector::operator+(const CVector& v) const {
	if (getDim() != v.getDim())
		throw invalid_argument("Khong cung chieu");

	CVector res(getDim());
	for (int i = 0; i < getDim(); ++i)
		res.data[i] = data[i] + v.data[i];
	return res;
}

CVector CVector::operator-(const CVector& v) const {
	if (getDim() != v.getDim()) 
		throw invalid_argument("Khong cung chieu");

	CVector res(getDim());
	for (int i = 0; i < getDim(); ++i) 
		res.data[i] = data[i] - v.data[i];
	return res;
}

double CVector::operator*(const CVector& v) const {
	if (getDim() != v.getDim())
		throw invalid_argument("Khong cung chieu");

	double sum = 0;
	for (int i = 0; i < getDim(); ++i)
		sum += data[i] * v.data[i];
	return sum;
}

CVector CVector::operator*(const double k) const {
	CVector res(getDim());
	for (int i = 0; i < getDim(); ++i)
		res.data[i] = data[i] * k;
	return res;
}

istream& operator>>(istream& in, CVector& v) {
	int dim;
	cout << "Nhap so chieu cua vector: ";
	in >> dim;
	v.data.resize(dim);

	for (int i = 0; i < dim; ++i) {
		cout << "Nhap toa do thu " << i + 1 << ": "; in >> v.data[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const CVector& v) {
	if (v.getDim() == 0) {
		out << "()";
		return out;
	}
	out << "(";
	for (int i = 0; i < v.getDim(); i++) {
		out << (v[i] == 0 ? 0 : v[i]); // in ra 0 hoac v[i] (xu li truong hop -0)
		if (i < v.getDim() - 1) out << ", ";
	}
	out << ")";
	return out;
}
