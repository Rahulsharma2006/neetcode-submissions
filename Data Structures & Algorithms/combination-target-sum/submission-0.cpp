class Solution {
public:
     void helper(vector<int>& nums,int i, int target, int sum ,vector<vector<int>>&ans, vector<int>&temp ){
        if(sum==target){
            ans.push_back(temp);
           return;
        }
        if(i==nums.size() || sum>target){
            return;
        }
       temp.push_back(nums[i]);
       sum+=nums[i];
       helper(nums,i,target,sum,ans,temp);
       temp.pop_back();
       sum-=nums[i];
       helper(nums,i+1,target,sum,ans,temp);
     }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = nums.size();
        helper(nums,0,target,0,ans,temp);
        return ans;
    }
};
