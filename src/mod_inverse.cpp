#include <iostream>

using namespace std;

// Hàm gcd giữ nguyên theo yêu cầu [cite: 83]
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm extended_euclid giữ nguyên theo yêu cầu [cite: 83]
int extended_euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int g = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

/**
 * Hoàn thiện hàm mod_inverse theo yêu cầu Q3 [cite: 67, 84]
 * Trả về x sao cho (a * x) % m == 1
 * Nếu không tồn tại, trả về -1 [cite: 93, 107]
 */
int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_euclid(a, m, x, y);
    
    if (g != 1) {
        return -1; 
    }
    
    return (x % m + m) % m;
}

int main() {
    int a, m;
    if (!(cin >> a >> m)) return 0;

    int result = mod_inverse(a, m);
    
    if (result == -1) {
        cout << "Nghich dao modulo khong ton tai." << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}