class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closetoOpen={
            {')','('},
            {'}','{'},
            {']','['}
        };
        stack<char > st;
        for(char ch : s){
            if(closetoOpen.count(ch)){
                if(!st.empty() && st.top() == closetoOpen[ch]){
                    st.pop();
                }else{
                    return false;
                }

            }else{
                st.push(ch);
            }
        }
        return st.empty();
    }
};
