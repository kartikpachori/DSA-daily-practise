class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int charCount[26] = {0};
        
        for (char c : s) {
            charCount[c - 'a']++;
        }
        
        for (char c : t) {
            charCount[c - 'a']--;
        }
        
        for (int count : charCount) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
};
