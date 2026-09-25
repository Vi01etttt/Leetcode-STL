#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        if (s.size() < 8) {
            cout << "Weak\n";
            continue;
        }

        bool hasLower = false;
        bool hasUpper = false;
        bool hasDigit = false;
        bool hasSpecial = false;

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                hasLower = true;
            } else if (c >= 'A' && c <= 'Z') {
                hasUpper = true;
            } else if (c >= '0' && c <= '9') {
                hasDigit = true;
            } else {
                hasSpecial = true;
            }
        }

        int typeCount = hasLower + hasUpper + hasDigit + hasSpecial;

        if (typeCount == 4) {
            cout << "Strong\n";
        } else if (typeCount == 3) {
            cout << "Medium\n";
        } else {
            cout << "Weak\n";
        }
    }

    return 0;
}
