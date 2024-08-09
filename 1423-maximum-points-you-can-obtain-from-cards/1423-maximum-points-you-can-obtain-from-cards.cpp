class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int rightsum=0,leftsum=0;
       
        for(int i=0;i<k;i++){
            leftsum+=cardPoints[i];
        }
        
        int totalsum = leftsum;
        int right_idx = cardPoints.size()-1;
        
        for(int i=k-1;i>=0;i--){
            leftsum=leftsum-cardPoints[i];
            rightsum+=cardPoints[right_idx];
            right_idx--;
            totalsum = max(totalsum,leftsum+rightsum);
        }
        
        return  totalsum;
    }
};