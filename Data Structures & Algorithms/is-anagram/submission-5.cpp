class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int count[26] = {0};
        for(char ch : s){
            count[ch - 'a']++;
        }
        for(char ch : t){
            count[ch - 'a']--;
        }
        for(int counts : count){
            if(counts != 0 ){
                return false;
            }
        }
        return true;
    }
};
