class Solution {
public:
    bool isPalindrome(string s) {
        int low =0;
        int high = s.size()-1;
        while(low<high){
                if(!isalnum(s[low])){
                    low++;
                    continue;
                }else if (!isalnum(s[high])){
                    high--;
                    continue;
                }
           else if(toupper(s[low])!= toupper(s[high])) return false;
         else{
            low++;
            high--;
         }
        }
        return true;
    }
};
