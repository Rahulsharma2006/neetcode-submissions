class Solution {
public:
  
    int maxSubArray(vector<int>& nums) {
      int ans = nums[0];
      int bestend = nums[0];
      for(int i =1;i<nums.size();i++){
        int take = bestend + nums[i];
        int notake = nums[i];
        bestend = max(take,notake);
        ans = max(ans , bestend);
      }
      return ans;
    }
};
