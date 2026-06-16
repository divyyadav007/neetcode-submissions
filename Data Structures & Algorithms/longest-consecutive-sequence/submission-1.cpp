class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        int maxLength = 1;
        int currLength =1;
        for(int i = 0; i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                continue;
            }
            if(nums[i]+1 == nums[i+1]){
                currLength++;
            }
            else{
                currLength = 1;
            }
            maxLength = max(maxLength, currLength);
        }
        return maxLength;
    }
};
