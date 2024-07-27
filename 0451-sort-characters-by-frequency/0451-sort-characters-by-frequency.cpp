class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count character frequencies
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        
        // Step 2: Store characters by frequency
        vector<pair<int, char>> freqVec;
        for (auto& entry : freqMap) {
            freqVec.push_back({entry.second, entry.first});
        }
        
        // Step 3: Sort by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), greater<>());
        
        // Step 4: Build the result string
        string result;
        for (auto& entry : freqVec) {
            result.append(entry.first, entry.second); // append 'entry.first' copies of 'entry.second'
        }
        
        return result;
    }
};
