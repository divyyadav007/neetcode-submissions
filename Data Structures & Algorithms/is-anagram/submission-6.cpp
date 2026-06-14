class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int> result(26,0);
       if(s.length() != t.length()){
            return false;
       }
       for (char ch : s){
            result[ch-'a']++;
       }
       for (char ch : t){
            result[ch-'a']--;
       }
       for(int count : result){
            if(count != 0){
                return false;
            }
       }
       return true;
       
    }        
};
