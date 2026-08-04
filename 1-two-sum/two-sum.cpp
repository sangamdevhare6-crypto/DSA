class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            int x = target - cur;

            if (map.find(x) != map.end()) {
                return {map[x], i};
            }

            map[cur] = i;
        }

        return {};
    }
};