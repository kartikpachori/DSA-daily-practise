class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> p_count(26, 0);  
        vector<int> s_count(26, 0);  
        
        int p_len = p.size();
        int s_len = s.size();
        
        if (p_len > s_len) return result; 
        for (int i = 0; i < p_len; ++i) {
            p_count[p[i] - 'a']++;
            s_count[s[i] - 'a']++;
        }
        if (p_count == s_count) {
            result.push_back(0);
        }
        for (int i = p_len; i < s_len; ++i) {
            s_count[s[i] - 'a']++;
            s_count[s[i - p_len] - 'a']--;
            if (p_count == s_count) {
                result.push_back(i - p_len + 1);
            }
        }       
        return result;
    }
};
