#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0;
        int answer = 0;
        int n = static_cast<int>(s.size());

        for (int right = 0; right < n; right++) {
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }

            window.insert(s[right]);
            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};
