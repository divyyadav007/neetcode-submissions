class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int k =0 ;
       for(int i : nums){
        if(nums[i] != val){
            nums[k]= nums[i];
            k++;
        }
       }
       return k;
    }
};