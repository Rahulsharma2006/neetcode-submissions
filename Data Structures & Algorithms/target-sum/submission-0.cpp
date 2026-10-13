class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (target < -sum || target > sum)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

        // Base case:
        // When no elements are left, only target = 0 is possible.
        dp[n][sum] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int t = -sum; t <= sum; t++) {

                int ways = 0;

                if (t - nums[i] >= -sum)
                    ways += dp[i + 1][(t - nums[i]) + sum];

                if (t + nums[i] <= sum)
                    ways += dp[i + 1][(t + nums[i]) + sum];

                dp[i][t + sum] = ways;
            }
        }

        return dp[0][target + sum];
    }
};