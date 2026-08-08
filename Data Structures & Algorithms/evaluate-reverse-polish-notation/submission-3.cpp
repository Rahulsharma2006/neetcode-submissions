class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(const string& ch : tokens){
            if(ch=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a+b);
            }
           else if(ch=="-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b-a);
            }
           else if(ch=="*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a*b);
            }
           else if(ch=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);
            }else{
                st.push(stoi(ch));
            }
        }
        if(st.size()==1)return st.top();
        return -1;
    }
};
