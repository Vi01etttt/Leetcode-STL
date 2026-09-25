#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int x : nums) {
            count[x]++;
        }

        for (auto& [num, freq] : count) {
            if (freq == 1) {
                return num;
            }
        }

        return 0;
    }
};

