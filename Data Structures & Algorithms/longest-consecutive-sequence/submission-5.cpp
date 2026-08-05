class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==0)return nums.size();
        unordered_map<int,int>freq;
        for(int i =0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int ans =0;
        for(auto a : freq){
         
            int val =a.first;
            if(freq.find(val-1)==freq.end()){
                int curr=0;
            while(freq.find(val)!=freq.end()){
                curr++;
                val++;
            }
            ans=max(curr,ans);
        }
        }
        return ans;
    }
};
