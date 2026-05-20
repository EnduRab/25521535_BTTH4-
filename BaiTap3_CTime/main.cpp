#include "CTime.h"
#include <iostream>
#include <windows.h>

using namespace std;

// Dùng để di chuyển con trỏ trên màn hình console đến một tọa độ x,y
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {

    CTime t;
    cout << "=== NHAP THOI GIAN ===" << endl;
    cin >> t;

    cout << "\nThoi gian ban vua nhap la:" << endl;
    cout << t;

    cout << "\n=== KIEM TRA TOAN TU CONG (+) ===" << endl;
    int secAdd = 3665; // 1 gio 1 phut 5 giay
    cout << "Cong them " << secAdd << " giay vao thoi gian hien tai:" << endl;
    CTime tPlus = t + secAdd;
    cout << tPlus;

    cout << "\n=== KIEM TRA TOAN TU TRU (-) ===" << endl;
    int secSub = 86400; // 24 gio 
    cout << "Tru di " << secSub << " giay tu thoi gian hien tai:" << endl;
    CTime tMinus = t - secSub;
    cout << tMinus;

    cout << "\n=== KIEM TRA TOAN TU TANG (++t) ===" << endl;
    cout << "Thoi gian truoc khi tang: " << endl;
    cout << t;
    cout << "Thoi gian sau khi tang 1 giay (++t): " << endl;
    ++t;
    cout << t;

    cout << "\n=== KIEM TRA TOAN TU GIAM (--t) ===" << endl;
    cout << "Thoi gian sau khi giam lai 1 giay (--t): " << endl;
    --t;
    cout << t;

    cout << "----> Nhap mot phim bat ky de in dong ho ben goc phai man hinh" << endl;
    system("pause");
    system("cls");
    gotoXY(10,10);
    cout << "Nhan Ctrl + C de dung chuong trinh";

    while (true) {
        // Di chuyển con trỏ tới sát mép phải màn hình (cột 100, hàng 0)
        // Việc gọi lại gotoXY tại cùng một vị trí sẽ khiến cout ghi đè lên nội dung cũ,
        gotoXY(100, 0);
        cout << t << flush;
        Sleep(1000); // Dừng chương trình 1s
        ++t;
    }

    return 0;
}