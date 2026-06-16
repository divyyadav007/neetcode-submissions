class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0; 
        int r = s.length() - 1;

        while(l < r) {
            // Sahi Fix 1: 'if' ki jagah 'while' lagaya taaki saare lagatar special characters skip ho sakein
            while(l < r && !isalnum(s[l])) {
                l++;
            }
            while(l < r && !isalnum(s[r])) {
                r--;
            }

            // Dono ko small cases me badal kar check kiya
            if(tolower(s[l]) != tolower(s[r])) {
                return false; // Mismatch milte hi galat declare kar do
            }
            
            // Agle characters par badho
            l++;
            r--;
        }

        // Sahi Fix 2: Agar poora loop makkhan tarah chal gaya, toh string palindrome hai!
        return true; 
    }
};