#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        // Agar s1, s2 se badi hai, toh uska permutation mil hi nahi sakta
        if (n1 > n2) return false;
        
        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);
        
        // Pehli window aur s1 ki frequency fill karo
        for (int i = 0; i < n1; i++) {
            s1Count[s1[i] - 'a']++;
            windowCount[s2[i] - 'a']++;
        }
        
        // Slide the window
        for (int i = 0; i < n2 - n1; i++) {
            // Check if current window matches
            if (s1Count == windowCount) return true;
            
            // Slide: purana character nikalo, naya character daalo
            windowCount[s2[i] - 'a']--;          // Removing left
            windowCount[s2[i + n1] - 'a']++;     // Adding right
        }
        
        // Last window check
        return s1Count == windowCount;
    }
};