class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // If no stones with remainder 1 or 2,
        // Alice cannot make the sum non-divisible by 3.
        if (cnt[1] == 0 && cnt[2] == 0)
            return false;

        // When count of remainder-0 stones is even,
        // Alice can win if both remainder-1 and remainder-2 exist
        // or one side has at least 2 stones.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // When count of remainder-0 stones is odd,
        // Alice can win if one remainder group has at least 2 more
        // stones than the other.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};