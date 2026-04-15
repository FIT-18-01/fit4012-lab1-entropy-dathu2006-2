#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <iomanip> // Thêm thư viện để định dạng output

using namespace std;

double calculate_entropy(const string &text) {
    if (text.empty()) return 0.0;

    map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    double entropy = 0.0;
    for (const auto &pair : freq) {
        double p = static_cast<double>(pair.second) / text.length();
        entropy -= p * log2(p);
    }
    return entropy;
}

double calculate_redundancy(const string &text, int alphabet_size = 256) {
    double entropy = calculate_entropy(text);
    // Max entropy của một nguồn tin có alphabet_size ký tự là log2(alphabet_size)
    double max_entropy = log2(alphabet_size);
    return max_entropy - entropy;
}

int main() {
    // Tăng tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    if (!getline(cin, input)) return 0;

    double entropy = calculate_entropy(input);
    double redundancy = calculate_redundancy(input);

    // Sử dụng setprecision để đảm bảo độ chính xác thập phân
    cout << fixed << setprecision(4) << entropy << endl;
    cout << fixed << setprecision(4) << redundancy << endl;

    return 0;
}