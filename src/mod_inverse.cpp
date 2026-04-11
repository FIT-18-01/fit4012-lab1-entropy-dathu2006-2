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

long long extended_euclid(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int mod_inverse(int a, int m) {
    long long x, y;
    long long g = extended_euclid((long long)a, (long long)m, x, y);
    if (g != 1) return -1; // Kiểm tra lại xem đề yêu cầu -1 hay 0
    return (x % m + m) % m;
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
