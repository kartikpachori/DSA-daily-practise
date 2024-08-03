
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char, int>> robots;
        
        // Combine position, health, direction, and index into one vector
        for (int i = 0; i < n; ++i) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }
        
        // Sort robots by position
        sort(robots.begin(), robots.end());
        
        stack<tuple<int, int, char, int>> st;  // Stack to keep track of robots
        vector<int> result(n, -1);  // Initialize result with -1 (indicating removed robots)
        
        for (const auto& robot : robots) {
            int pos = get<0>(robot);
            int health = get<1>(robot);
            char dir = get<2>(robot);
            int index = get<3>(robot);
            
            if (dir == 'R') {
                st.push(robot);  // Push all 'R' robots to stack
            } else {
                // Process collisions
                while (!st.empty() && get<2>(st.top()) == 'R') {
                    auto r_robot = st.top();
                    st.pop();
                    
                    if (get<1>(r_robot) > health) {
                        get<1>(r_robot) -= 1;
                        st.push(r_robot);
                        health = 0;
                        break;
                    } else if (get<1>(r_robot) < health) {
                        health -= 1;
                    } else {
                        health = 0;
                        break;
                    }
                }
                
                if (health > 0) {
                    st.push(make_tuple(pos, health, dir, index));
                }
            }
        }
        
        // Collect surviving robots' healths
        while (!st.empty()) {
            auto robot = st.top();
            st.pop();
            result[get<3>(robot)] = get<1>(robot);
        }
        
        // Filter out removed robots and return result
        vector<int> survivors;
        for (int h : result) {
            if (h != -1) survivors.push_back(h);
        }
        
        return survivors;
    }
};
