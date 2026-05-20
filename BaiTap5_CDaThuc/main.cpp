#include <iostream>
#include "CDaThuc.h"

using namespace std;

int main() {
	cDaThuc a, b;
	cout << "===== NHAP DA THUC A =====\n";
	cin >> a;
	cout << "===== NHAP DA THUC B =====\n";
	cin >> b;

	cout << "===== CAC DA THUC DA NHAP =====\n";
	cout << "A = " << a << endl;
	cout << "B = " << b << endl;

	double x;
	cout << "-----> Nhap x de tinh gia tri da thuc: ";
	cin >> x;
	cout << "===== GIA TRI CUA DA THUC KHI X = " << x << endl;
	cout << "A = " << a.tinhGiaTri(x) << endl;
	cout << "B = " << b.tinhGiaTri(x) << endl;

	cout << "===== CAC DAO HAM DA THUC =====\n";
	cout << "A' = " << a.daoHam() << endl;
	cout << "B' = " << b.daoHam() << endl;

	cout << "===== PHEP TOAN VOI DA THUC =====\n";
	cout << "A + B = " << a + b << endl;
	cout << "A - B = " << a - b << endl;
	cout << "A * B = " << a * b << endl;

}