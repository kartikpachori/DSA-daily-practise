
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/')) {
            if (token == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (!token.empty() && token != ".") {
                st.push(token); 
            }
        }
        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};
