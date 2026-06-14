class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int   l = 0 ; 
        int boats = 0;
        int r = people.size()-1 ;
        sort(people.begin(), people.end());
        while(l <= r){
            if( l == r){
                boats++;
                break;
            }else if( people[l] + people[r] <= limit ){
                boats++;
                l++;
                r--;
            }else if (people[l] + people[r] > limit){
            boats++;
            r--;
            }
        }
        return boats;
    }
};