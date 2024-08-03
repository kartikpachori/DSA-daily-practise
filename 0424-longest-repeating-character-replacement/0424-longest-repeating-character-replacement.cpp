class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0); // Frequency count of each character
        int left = 0, max_count = 0, max_length = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            // Update the frequency count of the current character
            max_count = max(max_count, ++count[s[right] - 'A']);
            
            // If the window size minus the count of the most frequent character is more than k
            // This means we need more than k replacements to make all characters in the window the                  same
            if (right - left + 1 - max_count > k) {
                // Shrink the window from the left
                --count[s[left] - 'A'];
                ++left;
            }
            
            // Update the maximum length of valid substring
            max_length = max(max_length, right - left + 1);
        }
        
        return max_length;
    }
};
