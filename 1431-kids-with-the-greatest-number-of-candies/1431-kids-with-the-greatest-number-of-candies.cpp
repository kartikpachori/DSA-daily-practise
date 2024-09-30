class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {       
        int maxCandies = *max_element(candies.begin(), candies.end());      
        vector<bool> result;
        for (int candy : candies) {
            if (candy + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        
        return result;
    }
};
