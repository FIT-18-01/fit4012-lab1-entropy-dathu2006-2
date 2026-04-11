#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int extended_euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1 = 0, y1 = 0;
    int g = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_euclid(a, m, x, y);
    if (g != 1) {
        // Nếu GCD(a, m) != 1, nghịch đảo không tồn tại
        return -1;
    }
    // Đảm bảo x là số dương
    x = (x % m + m) % m;
    return x;
}

int main() {
    int a, m;
    cout << "Nhap a, m: ";
    cin >> a >> m;

    if (a <= 0 || m <= 0) {
        cout << "a và m phải là các số nguyên dương." << endl;
        return 1;
    }

    int result = mod_inverse(a, m);
    if (result == -1) {
        cout << "Nghịch đảo modulo không tồn tại." << endl;
    } else {
        cout << "Nghịch đảo modulo của " << a << " theo modulo " << m << " là: " << result << endl;
    }

    return 0;
}
