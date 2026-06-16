class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // Isme hum apne answers (triplets) daalenge
vector<vector<int>> result;

        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > 0) break;
            else if(i > 0 && nums[i] == nums[i-1]) continue;
            //take two pointer as I is starting one
            int l = i+1; //start one ahead from i 
            int r = nums.size()-1;
            while(l < r) //not cross each other
            int sum = nums[i]+nums[l]+nums[r];
            if(sum > 0) {
                r--;
            }
            else if (sum < 0){
                l--;
            }
            else //sum==0 //got the result 
            {
                result.push_back({nums[i], nums[j], nums[r]});
                l++;
                r--;
                while(l<r) //make sure they dont cross each other , which result into take duplicate calues
                if(l < r && nums[l]== nums[l+1]){
                    l++;
                }
            }
        }
        return result;
    }
};
