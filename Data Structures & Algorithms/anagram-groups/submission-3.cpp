class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> mp;
      vector<vector<string>> ans;

      for(int i = 0 ; i < strs.size();i++){
        string org= strs[i];
        string sorted = org;
        sort(sorted.begin(), sorted.end());
        mp[sorted].push_back(org);
      }
      for(auto it: mp){
        ans.push_back(it.second);
      }
      return ans;
    }
};
