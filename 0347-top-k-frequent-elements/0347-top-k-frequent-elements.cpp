class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        int n = nums.size();
        vector<vector<int>> buckets(n + 1); 
        for (auto& [num, freq] : freqMap) {
            buckets[freq].push_back(num);
        }
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    break;
                }
            }
        }        
        return result;
    }
};
