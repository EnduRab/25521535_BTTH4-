#include "CSoPhuc.h"
#include <stdexcept>

CSoPhuc::CSoPhuc(float a, float b) : thuc(a), ao(b) {}

std::istream& operator>>(std::istream& in, CSoPhuc& sp) {
	std::cout << "Nhap phan thuc: ";
	in >> sp.thuc;
	std::cout << "Nhap phan ao: ";
	in >> sp.ao;
	return in;
}

std::ostream& operator<<(std::ostream& out,  const CSoPhuc& sp) {
	out << sp.thuc;
	if (sp.ao == 0)
		return out;
	else if (sp.ao > 0)
		out << " + " << sp.ao;
	else if (sp.ao < 0)
		out << " - " << sp.ao * -1;
	out << "i";
	return out;
}

CSoPhuc CSoPhuc::operator+(const CSoPhuc& other) {
	return CSoPhuc(thuc + other.thuc, ao + other.ao); // Sử dụng constructor trả về tổng 2 số phức
}

CSoPhuc CSoPhuc::operator-(const CSoPhuc& other) {
	return CSoPhuc(thuc - other.thuc, ao - other.ao); // Sử dụng constructor trả về hiệu 2 số phức
}

CSoPhuc CSoPhuc::operator*(const CSoPhuc& other) {
	CSoPhuc tich;
	tich.thuc = (thuc * other.thuc - ao * other.ao);
	tich.ao = (thuc * other.ao + ao * other.thuc);
	return tich;
}

CSoPhuc CSoPhuc::operator/(const CSoPhuc& other) {
	float mauSo = other.thuc * other.thuc + other.ao * other.ao;
	if (mauSo == 0) {
		throw std::invalid_argument("Khong the chia cho so phuc 0!\n");
	}
	CSoPhuc thuong;
	thuong.thuc = (thuc * other.thuc + ao * other.ao) /
										(other.thuc * other.thuc + other.ao * other.ao);
	thuong.ao = (ao * other.thuc - other.ao * thuc) /
										(other.thuc * other.thuc + other.ao * other.ao);
	return thuong;
}

bool CSoPhuc::operator==(const CSoPhuc& other) {
	return (thuc == other.thuc && ao == other.ao);
}

bool CSoPhuc::operator!=(const CSoPhuc& other) {
	return !(*this == other);
}