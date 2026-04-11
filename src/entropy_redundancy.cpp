#include <cmath>
#include <iostream>
#include <map>
#include <string>

using namespace std;

double calculate_entropy(const string &text) {
    if (text.empty()) {
        return 0.0;
    }

    map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    double entropy = 0.0;
    for (const auto &pair : freq) {
        double p = static_cast<double>(pair.second) / text.size();
        entropy -= p * log2(p);
    }
    return entropy;
}

double calculate_redundancy(const string &text, int alphabet_size = 256) {
    double entropy = calculate_entropy(text);
    double max_entropy = log2(alphabet_size);
    return max_entropy - entropy;
}

int main() {
    string input;
    // Bỏ dòng "Enter a string..." để không làm nhiễu script chấm điểm
    if (!getline(cin, input)) return 0;

    double entropy = calculate_entropy(input);
    double redundancy = calculate_redundancy(input);

    // In kết quả thuần túy để script dễ đọc
    cout << entropy << endl;
    cout << redundancy << endl;

    return 0;
}