#pragma once

#include <iostream>
#include <vector>

class cDaThuc {
private:
    std::vector<double> heSo;
    void chuanHoa(); // cat bo cac he so = 0 khi tinh +,-,*
public:

    // Constructor
    cDaThuc();
    cDaThuc(int);
    cDaThuc(const std::vector<double>&);

    // Tinh gia tri cua da thuc khi biet x
    double tinhGiaTri(double x) const;
    cDaThuc daoHam() const;

    // Phep toan voi da thuc
    cDaThuc operator+(const cDaThuc&) const;
    cDaThuc operator-(const cDaThuc&) const;
    cDaThuc operator*(const cDaThuc&) const;

    // Nhap va xuat da thuc
    friend std::istream& operator>>(std::istream&, cDaThuc&);
    friend std::ostream& operator<<(std::ostream&, const cDaThuc&);
};

