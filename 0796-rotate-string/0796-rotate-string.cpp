// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if (s.length() != goal.length()) {
//             return false;
//         }
//         string doubled_s = s + s;
//         return doubled_s.find(goal) != string::npos;
//     }
// };
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (s.substr(i) + s.substr(0, i) == goal) {
                return true;
            }
        }
        return false;
    }
};

