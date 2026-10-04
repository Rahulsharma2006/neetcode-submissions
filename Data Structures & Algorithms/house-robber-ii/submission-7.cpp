class Solution {
public:

    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];

          int n = nums.size();
           int prev = nums[n-1];
           int prev_prev =0;
           int ans1 =prev;
           
        for(int i =n-2;i>0;i--){
           
             ans1=max(prev,nums[i]+prev_prev);
             prev_prev=prev;
             prev=ans1;

        }
          prev=nums[n-2];
          prev_prev=0;
          int ans2 = prev;
          for(int i =n-3;i>=0;i--){
            ans2=max(prev,nums[i]+prev_prev);
             prev_prev=prev;
             prev=ans2;
        }
        return max(ans1,ans2);
    }
};
