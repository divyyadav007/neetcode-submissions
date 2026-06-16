class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        sort(strs.begin(), strs.end());

        string first= strs[0];
        string last = strs[strs.size()-1];
        for(int i = 0; i < strs.size();i++){
            if(first[i] == last[i]){
                res.push_back(first[i]);
            }
            else{
               break;
            }
        }
        if(first[0] != last[0]){
            return "";
        }else 
        return res;
        
    }
};