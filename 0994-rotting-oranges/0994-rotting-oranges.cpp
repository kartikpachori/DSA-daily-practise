class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> rotten;
        int freshOranges = 0;
        
 
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }


        if (freshOranges == 0) return 0;

        int minutes = 0;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
 
        while (!rotten.empty()) {
            int size = rotten.size();
            bool rottedAny = false;
            for (int i = 0; i < size; i++) {
                auto [row, col] = rotten.front();
                rotten.pop();
                
                for (auto dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    
                  
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        rotten.push({newRow, newCol});
                        freshOranges--;
                        rottedAny = true;
                    }
                }
            }
            if (rottedAny) minutes++;
        }
        
   
        return freshOranges == 0 ? minutes : -1;
    }
};
