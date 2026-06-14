class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
          //create map
        unordered_map<int , int> freq;
        for(int num : nums){
            freq[num]++;
        }

        //create bucket 
        vector<vector<int>> bucket(n+1);
        for(auto it : freq){
            int number = it.first;
            int count = it.second;
            bucket[count].push_back(number);
        }

        vector<int> ans;
        for(int i = n; i >=0 && ans.size() < k ;i--){
            for(int num : bucket[i]){
                ans.push_back(num);
                if(ans.size()==k)
                break;
            }
        }
        return ans;
    }
};