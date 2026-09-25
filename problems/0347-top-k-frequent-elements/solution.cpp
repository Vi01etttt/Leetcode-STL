#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        for (int num : nums) {
            frequency[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto& entry : frequency) {
            int num = entry.first;
            int count = entry.second;
            buckets[count].push_back(num);
        }

        vector<int> answer;

        for (int count = static_cast<int>(nums.size()); count >= 1; count--) {
            for (int num : buckets[count]) {
                answer.push_back(num);

                if (answer.size() == static_cast<size_t>(k)) {
                    return answer;
                }
            }
        }

        return answer;
    }
};
