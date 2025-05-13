// Leetcode: 20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char &ch: s){
            if(st.empty()){
                if(ch == ')' || ch == '}' || ch == ']'){
                    return false;
                }
                else{
                    st.push(ch);
                }
            }
            else{
                char top = st.top();

                if(ch == '(' || ch == '{' || ch == '['){
                    st.push(ch);
                }
                else if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }

        return false;
    }
};
