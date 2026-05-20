#include "CVector.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	CVector a,b;
	cout << "===== NHAP VECTOR a =====\n";
	cin >> a;
	cout << "===== NHAP VECTOR b =====\n";
	cin >> b;

	cout << "===== VECTOR DA NHAP =====\n";
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	
	cout << "===== CAC PHEP TINH VOI VECTOR =====\n";
	try {
		cout << "a + b = " << a + b << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Loi: " << e.what() << endl;
	}

	try {
		cout << "a - b = " << a - b << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Loi: " << e.what() << endl;
	}

	try {
		cout << "a * b = " << a * b << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Loi: " << e.what() << endl;
	}

	int k;
	cout << "Nhap k: "; cin >> k;
	cout << "Vector k*a = " << a * k << endl;
	cout << "Vector k*b = " << b * k << endl;
}