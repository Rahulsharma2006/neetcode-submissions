class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>subset;
        dfs(nums,0,res,subset,nums.size());
        return res;
    }
    void dfs(vector<int>& nums,int i ,  vector<vector<int>>&res,vector<int>& subset, int n){
        if(i>=n){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums,i+1,res,subset,nums.size());
        subset.pop_back();
         dfs(nums,i+1,res,subset,nums.size());
    }
};
