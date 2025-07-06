class Solution {
  public:
    vector<int> minPartition(int N) {
        // All denominations in decreasing order
        vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        
        vector<int> result;
        
        for(int i=0; i<denominations.size(); i++){
            int coin = denominations[i];
            
            while(N >= coin){
                N -= coin;
                result.push_back(coin);
            }
        }
        
        return result;
    }
};
