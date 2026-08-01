class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
     unordered_map<int,int>mp;
     for(int i =0;i<nums.size();i++){
        mp[nums[i]]++;
     }
     for(int num : nums){
        mp[num]--;
        if(mp[num]>0)return true;
     }
     return false;
    }
};