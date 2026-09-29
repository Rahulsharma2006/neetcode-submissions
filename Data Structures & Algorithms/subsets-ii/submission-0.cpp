class Solution {
public:
   vector<vector<int>>ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<int>temp;
       backtrack(0,{},nums);
       return ans; 
    }
    void backtrack(int i, vector<int>temp,vector<int>&nums){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        backtrack(i+1,temp,nums);
        temp.pop_back();
        while(i<nums.size()-1&& nums[i]==nums[i+1])i++;

        backtrack(i+1,temp,nums);
    }
};
