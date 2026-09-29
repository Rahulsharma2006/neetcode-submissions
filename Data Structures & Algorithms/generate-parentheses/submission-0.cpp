class Solution {
public:
   vector<string>ans;
    vector<string> generateParenthesis(int n) {
        string temp;
        backtrack(0,0,n,temp);
        return ans;
    }
    void backtrack(int open , int close , int n , string temp){
        if(close==n){
            ans.push_back(temp);
            return;
        }
        if(open<n){
            temp.push_back('(');
            backtrack(open+1,close,n,temp);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            backtrack(open,close+1,n,temp);
            temp.pop_back();
        }
    }
};
