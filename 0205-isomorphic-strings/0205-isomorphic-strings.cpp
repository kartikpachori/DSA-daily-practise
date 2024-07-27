class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, char> mapS, mapT;
        
        for (int i = 0; i < s.length(); ++i) {
            char cs = s[i];
            char ct = t[i];
            
            // If there is already a mapping for cs but it doesn't match ct
            if (mapS.count(cs) && mapS[cs] != ct) {
                return false;
            }
            
            // If there is already a mapping for ct but it doesn't match cs
            if (mapT.count(ct) && mapT[ct] != cs) {
                return false;
            }
            
            // Create or update the mapping
            mapS[cs] = ct;
            mapT[ct] = cs;
        }
        
        return true;
    }
};