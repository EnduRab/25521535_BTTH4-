#include "CMatrix.h"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
	CMatrix A, B;
	cout << "===== NHAP MA TRAN A =====\n";
	cin >> A;

	cout << "===== NHAP MA TRAN B =====\n";
	cin >> B;

	cout << "===== MA TRAN A =====\n";
	cout << A << endl;

	cout << "===== MA TRAN B ======\n";
	cout << B << endl;

	int k;
	cout << "---Nhap he so k de tinh A * k, B * k\n";
	cout << "------> k: ";
	cin >> k;

	cout << "===== CAC PHEP TINH VOI MA TRAN =====\n";
	cout << "--- A * " << k << " ---\n" << A * k << endl;
	cout << "--- B * " << k << " ---\n" << B * k << endl;

	try {
		cout << "--- A + B ---\n" << A + B << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Loi: " << e.what() << endl;
	}

	try {
		cout << "--- A - B ---\n" << A - B << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Loi: " << e.what() << endl;
	}

	try {
		cout << "--- A * B ---\n" << A * B << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Loi: " << e.what() << endl;
	}
	CVector a;
	cout << "===== NHAP VECTOR DE TINH TINH CUA MA TRAN VA VECTOR (LUU Y: SO COT MA TRAN PHAI = KICH THUOC VECTOR) =====\n";
	cin >> a;

	try {
		cout << "---> Tich cua ma tran A va vector la: " << A * a << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Loi: " << e.what() << endl;
	}

	try {
		cout << "---> Tich cua ma tran B va vector la: " << B * a << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Loi: " << e.what() << endl;
	}

	cout << "===== MA TRAN CHUYEN VI =====\n";
	cout << "--- MA TRAN CHUYEN VI A ---\n";
	cout << A.transpose() << endl;
	cout << "--- MA TRAN CHUYEN VI B ---\n";
	cout << B.transpose() << endl;
}