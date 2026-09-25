#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        long long sum = 0;
        int maxValue = 0;
        int allAnd = (1 << 30) - 1;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;

            sum += value;
            maxValue = max(maxValue, value);
            allAnd &= value;
        }

        int bitLength = 1;
        while ((1LL << bitLength) <= maxValue) {
            bitLength++;
        }

        int validMask = static_cast<int>((1LL << bitLength) - 1);
        int minX = (~allAnd) & validMask;
        long long maxSum = sum + minX;

        cout << maxSum << ' ' << minX << '\n';
    }

    return 0;
}
