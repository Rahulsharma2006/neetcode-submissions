class Solution {
public:
    int findMin(vector<int> &nums) {
       int n = nums.size()-1;
       int end = n;
       int st =0;
       while(st<end){
        int mid = (st+end)/2;
        if(nums[mid]>nums[n]){
            st = mid+1;
        }else{
            end=mid;
        }

       }
       return nums[st];
    }
};
