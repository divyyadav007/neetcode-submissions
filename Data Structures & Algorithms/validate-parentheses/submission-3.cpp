class Solution {
private:
    bool isMatching(char open , char close){
        return (open == '[' && close == ']') ||
        (open == '(' && close == ')') ||
        (open == '{' && close == '}');
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }else{
                if(st.empty()){
                    return false;
                }
                if(!isMatching(st.top(),ch)){
                    return false;
                }
                
                st.pop();    
            }
            
        }
        return st.empty();
    }
};
