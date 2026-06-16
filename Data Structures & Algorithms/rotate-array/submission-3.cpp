class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size()-1;
         k%=n;
         reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);

         reverse(nums.begin()+k, nums.end());


    }private:
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};