class Solution {
public:
    int characterReplacement(string s, int k) {
        int low =0;
        int ans =0;
        int maxfreq=0;
        unordered_map<char,int>freq;
        for(int high =0;high<s.size();high++){
            freq[s[high]]++;
            int leng = high-low+1;
            maxfreq= max(maxfreq,freq[s[high]]);
            int changes = leng - maxfreq;
            while(changes>k){
                freq[s[low]]--;
                low++;
                leng = high-low+1;
                changes = leng - maxfreq;
            }
            ans = max(ans,high-low+1);
        }
        return ans;
    }
};
