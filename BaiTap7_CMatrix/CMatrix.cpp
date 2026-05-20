#include "CMatrix.h"

using namespace std;

CMatrix::CMatrix(int rows, int cols): hang(rows), cot(cols) {
	data.resize(hang, vector<double>(cot,0));
}

double& CMatrix::operator()(int i, int j) {
	if (i < 0 || i >= hang || j < 0 || j >= cot) {
		throw out_of_range("Chi so vuot ngoai pham vi");
	}
	return data[i][j];
}

double CMatrix::operator()(int i, int j) const {
	if (i < 0 || i >= hang || j < 0 || j >= cot) {
		throw out_of_range("Chi so vuot ngoai pham vi");
	}
	return data[i][j];
}

CMatrix CMatrix::operator+(const CMatrix& other) const {
	if (hang != other.hang || cot != other.cot)
		throw invalid_argument("Hai ma tran phai co cung kich thuoc!");
	CMatrix res(hang, cot);
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < cot; ++j) {
			res(i, j) = (*this)(i, j) + other(i, j);
		}
	}
	return res;
}

CMatrix CMatrix::operator-(const CMatrix& other) const {
	if (hang != other.hang || cot != other.cot)
		throw invalid_argument("Hai ma tran phai co cung kich thuoc!");
	CMatrix res(hang, cot);
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < cot; ++j) {
			res(i, j) = (*this)(i, j) - other(i, j);
		}
	}
	return res;
}

CMatrix CMatrix::operator*(const double k) const {
	CMatrix res(hang, cot);
	for (int i = 0; i < hang; ++i)
		for (int j = 0; j < cot; ++j)
			res(i, j) = data[i][j] * k;
	return res;
}

CMatrix CMatrix::operator*(const CMatrix& other) const {
	if (cot != other.hang)
		throw invalid_argument("So cot A phai bang so hang B!");
	CMatrix res(hang, other.cot);
	for (int i = 0; i < hang; ++i)
		for (int j = 0; j < other.cot; ++j)
			for (int k = 0; k < cot; ++k)
				res(i, j) += data[i][k] * other.data[k][j];
	return res;
}

CVector CMatrix::operator*(const CVector& v) const {
	if (cot != v.getDim())
		throw invalid_argument("So cot ma tran phai bang kich thuoc vector!");
	CVector res(hang);
	for (int i = 0; i < hang; ++i)
		for (int j = 0; j < cot; ++j)
			res[i] += data[i][j] * v[j];
	return res;
}

CMatrix CMatrix::transpose() const {
	CMatrix res(cot, hang); // đổi hàng/cột
	for (int i = 0; i < hang; ++i)
		for (int j = 0; j < cot; ++j)
			res(j, i) = data[i][j];
	return res;
}

istream& operator>>(istream& in, CMatrix& m) {
	do {
		cout << "Nhap so hang: "; in >> m.hang;
		cout << "Nhap so cot: "; in >> m.cot;
		if (m.hang <= 0 || m.cot <= 0) cout << "So hang hoac so cot phai > 0\n";
	} while (m.hang <= 0 || m.cot <= 0);
	m.data.clear();
	m.data.resize(m.hang, vector<double>(m.cot, 0));

	cout << "--- nhap cac phan tu ---\n";
	for (int i = 0; i < m.hang; ++i)
		for (int j = 0; j < m.cot; ++j)
			in >> m.data[i][j];
	return in;
}

ostream& operator<<(ostream& os, const CMatrix& m) {
	for (int i = 0; i < m.hang; ++i) {
		for (int j = 0; j < m.cot; ++j)
			os << (m.data[i][j] == 0 ? 0 : m.data[i][j]) << " "; // xu ly truong hop -0 thanh 0
		os << "\n";
	}
	return os;
}