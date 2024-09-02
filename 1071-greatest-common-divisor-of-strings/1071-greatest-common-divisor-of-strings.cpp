
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Helper function to check if s can be constructed by repeating base
        auto canConstruct = [](const string &s, const string &base) -> bool {
            if (s.length() % base.length() != 0) return false;
            string repeated = "";
            for (int i = 0; i < s.length() / base.length(); ++i) {
                repeated += base;
            }
            return repeated == s;
        };
        
        int len1 = str1.length();
        int len2 = str2.length();
        int gcdLength = gcd(len1, len2); // Compute GCD of lengths
        
        // Potential base string is the substring of length gcdLength from str1
        string base = str1.substr(0, gcdLength);
        
        // Check if this base can construct both str1 and str2
        if (canConstruct(str1, base) && canConstruct(str2, base)) {
            return base;
        } else {
            return "";
        }
    }
};
