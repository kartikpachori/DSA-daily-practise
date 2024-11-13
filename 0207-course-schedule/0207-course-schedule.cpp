class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            graph[prerequisiteCourse].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int processedCourses = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            processedCourses++;
            
            for (int nextCourse : graph[course]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        return processedCourses == numCourses;
    }
};
