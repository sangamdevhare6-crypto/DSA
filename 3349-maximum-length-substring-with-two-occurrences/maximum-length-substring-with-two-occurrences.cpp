class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[s[right]]++;

            // If any character occurs more than 2 times
            while (freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }

            // Current valid window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};