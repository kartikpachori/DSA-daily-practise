class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int totalBeauty = 0;
        
        // Iterate over all possible substrings
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0); // frequency array for characters 'a' to 'z'
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;
                
                int maxFreq = 0;
                int minFreq = n;
                
                // Find the max and min frequencies in the current substring
                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                
                totalBeauty += (maxFreq - minFreq);
            }
        }
        
        return totalBeauty;
    }
};
