class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int maxCount = 0, currentCount = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                currentCount++;
            }
        }
        maxCount = currentCount;
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i])) {
                currentCount++; 
            }
            if (isVowel(s[i - k])) {
                currentCount--; 
            }
            maxCount = max(maxCount, currentCount);
        }
        return maxCount;
    }
};
