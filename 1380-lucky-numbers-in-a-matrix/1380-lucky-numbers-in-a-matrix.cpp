class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNums;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Find the minimum element in each row
        for (int i = 0; i < rows; i++) {
            int minElem = matrix[i][0];
            int minCol = 0;
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] < minElem) {
                    minElem = matrix[i][j];
                    minCol = j;
                }
            }
            
            // Check if this min element is the maximum in its column
            bool isLucky = true;
            for (int k = 0; k < rows; k++) {
                if (matrix[k][minCol] > minElem) {
                    isLucky = false;
                    break;
                }
            }
            
            if (isLucky) {
                luckyNums.push_back(minElem);
            }
        }
        
        return luckyNums;
    }
};
