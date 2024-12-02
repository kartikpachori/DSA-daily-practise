class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;  
        int read = 0;   
        while (read < n) {
            char currentChar = chars[read];
            int count = 0;
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }
            chars[write++] = currentChar;
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};
