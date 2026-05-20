#include "CPhanSo.h"
#include <iostream>

using namespace std;

int main() {
	CPhanSo a, b;
	cout << "===== NHAP PHAN SO A =====\n";
	cin >> a;
	cout << "===== NHAP PHAN SO B ======\n";
	cin >> b;

	cout << "===== CAC PHAN SO DA NHAP =====\n";
	cout << "-->PHAN SO A: " << a << endl;
	cout << "-->PHAN SO B: " << b << endl;

	cout << "====== CAC PHEP TINH VOI PHAN SO =====\n";
	cout << "A + B = " << a + b << endl;
	cout << "A - B = " << a - b << endl;
	cout << "A x B = " << a * b << endl;
	cout << "A / B = " << a / b << endl;
	
	cout << "===== SO SANH 2 PHAN SO A VA B =====\n";
	cout << "A > B: " << ((a > b) ? "true" : "false") << endl;
	cout << "A < B: " << ((a < b) ? "true" : "false") << endl;
	cout << "A == B: " << ((a == b) ? "true" : "false") << endl;
}