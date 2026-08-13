class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>freq;
       int low =0;
       int ans =0;
       int n = s.size();
       for(int high =0;high<n;high++){
        freq[s[high]]++;
        while(freq[s[high]]>1){
             freq[s[low]]--;
            low++;
           
        }
          ans = max(ans,high-low+1);
       }
       return ans;
    }
};
