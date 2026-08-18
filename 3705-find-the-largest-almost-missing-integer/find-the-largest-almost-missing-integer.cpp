class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;

        // Har size-k subarray check karo
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> seen;

            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            // Ek subarray mein number ko sirf ek baar count karo
            for (int x : seen) {
                count[x]++;
            }
        }

        int ans = -1;

        // Exactly one subarray mein aane wala largest number
        for (auto& [x, freq] : count) {
            if (freq == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};