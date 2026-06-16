class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
          int n = nums.size();
    vector<int> res;

    for (int i = 0; i < n; i++) {
        
        // Count the frequency of arr[i]
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (nums[j] == nums[i])
                cnt += 1;
        }
      
        // Check if arr[i] is a majority element
        if (cnt > (n / 3)) {
          
            // Add arr[i] only if it is not already
            // present in the result
            if (res.size() == 0 || nums[i] != res[0]) {
                res.push_back(nums[i]);
            }
        }
      
        // If we have found two majority elements, 
        // we can stop our search
        if (res.size() == 2) {
            if(res[0] > res[1])
                swap(res[0], res[1]);
            break;
        }
    }

    return res;
    }
};