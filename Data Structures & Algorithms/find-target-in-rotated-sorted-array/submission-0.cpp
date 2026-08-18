class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e = nums.size()-1;
        int n = nums.size();
       while(s<=e){
        int mid = (s+e)/2;
        //Base Condition 
        if(nums[mid]==target) return mid;

        //Part 1
        if(nums[mid]>nums[n-1]){
            if(nums[mid]<target) s=mid+1;
            else
           {
                if(nums[0]>target) s=mid+1;
                else e=mid-1;
            }
        }
        //Part 2
          else{
            if(nums[mid]>target){
                e=mid-1;
            }
            if(nums[mid]<target){
                if(nums[n-1]<target) e=mid-1;
                else s=mid+1;
            }
          }
       }
       return -1;
    }
};