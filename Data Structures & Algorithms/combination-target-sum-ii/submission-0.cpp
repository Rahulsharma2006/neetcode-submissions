class Solution {
public:

    void helper(vector<int>& nums, int i, int target,
                vector<vector<int>>& ans, vector<int>& temp) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < nums.size(); j++) {

            // Same level par duplicate skip
            if (j > i && nums[j] == nums[j - 1])
                continue;

            // Since sorted
            if (nums[j] > target)
                break;

            temp.push_back(nums[j]);

            // j+1 => same element reuse nahi hoga
            helper(nums, j + 1, target - nums[j], ans, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        helper(candidates, 0, target, ans, temp);

        return ans;
    }
};