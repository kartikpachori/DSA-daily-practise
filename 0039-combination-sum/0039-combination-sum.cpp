class Solution {
private:
    void ans(vector<vector<int>>& res, vector<int>& curr, vector<int>& candidates, int &target, int curr_sum, int i) {
        if(curr_sum == target) {
            res.push_back(curr);
            return;
        }
        if(i >= candidates.size() || curr_sum > target) {
            return;
        }
        
        curr.push_back(candidates[i]);
        ans(res, curr, candidates, target, curr_sum+candidates[i], i);
        curr.pop_back();

        if (i + 1 < candidates.size()) {  
            ans(res, curr, candidates, target, curr_sum, i + 1);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        ans(res, curr, candidates, target, 0, 0);

        return res;
    }
};