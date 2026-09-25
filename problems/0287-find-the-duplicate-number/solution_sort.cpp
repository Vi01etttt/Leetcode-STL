#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }

        return 0;
    }
};

