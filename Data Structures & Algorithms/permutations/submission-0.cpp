class Solution {
public:
  vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<bool>vis(nums.size(),false);
        backtrack(nums,temp,vis);
        return ans;
    }
    void backtrack(vector<int>& nums,vector<int>& temp,vector<bool>& vis){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i =0;i<nums.size();i++){
            if(!vis[i]){
                temp.push_back(nums[i]);
                vis[i]=true;
                   backtrack(nums,temp,vis);
                   temp.pop_back();
                   vis[i]=false;
            }
        }
    }
};
