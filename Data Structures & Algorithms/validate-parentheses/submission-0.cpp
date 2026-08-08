class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0) return true;
    
    stack<char>st;
    st.push(s[0]);
    for(int i =1;i<s.size();i++){
    if(s[i] =='('|| s[i] =='{'|| s[i] =='['){
        st.push(s[i]);
    }else{
    if(s[i] =='}' || s[i]==']' || s[i]==')'){
        if(st.empty()) return false;
         if( st.top() =='{' && s[i]=='}'||
          st.top()=='[' && s[i]==']'||
          st.top() =='(' && s[i]==')'
         ){
        st.pop();
         }else{
            return false;
         }
    }
    }
    }
    if(st.empty()) return true;
     else return false;
    }
};