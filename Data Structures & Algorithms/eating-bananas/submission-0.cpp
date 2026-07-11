class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left =1 ; 
        int right = 0;
        for(int pile :piles){
            right = max(right, pile);
        }
        int ans = right;
        while(left<=right){
            int mid = left + (right - left)/2;
            long long totalHours = 0;
            for(int p : piles){
                totalHours +=ceil(double(p)/mid);
            }
            if(totalHours <= h){
                ans = mid;
                right = mid -1;

            } else {
                left = mid +1;
            }
        }
        return ans;
    }   
};
