class Solution {
public:
   vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        backtrack(s,0,temp);
        return ans;
    }
    void backtrack(string s, int i , vector<string>temp){
        if(i>=s.size()){
            ans.push_back(temp);
            return;
        }
        for(int l =i;l<s.size();l++){
            if(palindrome(s,i,l)){
                temp.push_back(s.substr(i,l-i+1));
                 backtrack(s,l+1,temp);
                 temp.pop_back();
            }
        }
    }
    bool palindrome(string s , int l , int r){
        while(l<r){
            if(s[l]!=s[r])return false;

            l++;
            r--;
        }
        return true;
    }

};
