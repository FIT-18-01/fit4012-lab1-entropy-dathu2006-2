#include <iostream>

// Hàm gcd có sẵn, giữ nguyên theo yêu cầu 
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm extended_euclid có sẵn, giữ nguyên theo yêu cầu 
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
 * Nếu không tồn tại, trả về -1 [cite: 93]
 */
int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_euclid(a, m, x, y);
    
    // Điều kiện tồn tại: gcd(a, m) = 1 [cite: 50, 57]
    if (g != 1) {
        return -1; 
    }
    
    // Đảm bảo kết quả là số dương trong khoảng [0, m-1]
    return (x % m + m) % m;
}