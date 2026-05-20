#include "CSoPhuc.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
	CSoPhuc a, b;

	cout << "--- NHAP SO PHUC A ---\n";
	cin >> a;
	cout << "--- NHAP SO PHUC B ---\n";
	cin >> b;

	cout << "--- SO PHUC DA NHAP ---\n";
	cout << "So phuc A: " << a << endl;
	cout << "So phuc B: " << b << endl;

	cout << "--- CAC PHEP TINH VOI SO PHUC ---\n";
	cout << "A + B = " << a + b << endl;
	cout << "A - B = " << a - b << endl;
	cout << "A * B = " << a * b << endl;
	try {
		cout << "A / B = " << a / b << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Loi: " << e.what() << endl;
	}
	
	cout << "--- SO SANH 2 SO PHUC ---\n";
	cout << "A == B: " << (a == b) << endl;
	cout << "A != B: " << (a != b) << endl;
}