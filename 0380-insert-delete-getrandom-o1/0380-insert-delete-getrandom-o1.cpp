class RandomizedSet {
private:
    vector<int> nums;                      
    unordered_map<int, int> valueToIndex;  

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valueToIndex.find(val) != valueToIndex.end()) {
            return false; 
        }
        nums.push_back(val);                
        valueToIndex[val] = nums.size() - 1; 
        return true;
    }

    bool remove(int val) {
        if (valueToIndex.find(val) == valueToIndex.end()) {
            return false; 
        }
        int lastElement = nums.back();       
        int idx = valueToIndex[val];            
        nums[idx] = lastElement;                 
        valueToIndex[lastElement] = idx;        
        nums.pop_back();                         
        valueToIndex.erase(val);                 
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();  
        return nums[randomIndex];               
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */