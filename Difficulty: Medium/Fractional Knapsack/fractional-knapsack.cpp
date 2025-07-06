// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        // Store (value/weight ratio, index) for each item
        vector<pair<double, int>> items;
        for(int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, i});
        }
        
        // Sort items by decreasing ratio
        sort(items.rbegin(), items.rend());
        
        double total_value = 0.0;
        int remaining_capacity = capacity;
        
        // Process items
        for(auto &item : items) {
            int idx = item.second;
            double ratio = item.first;
            
            if(remaining_capacity >= wt[idx]) {
                // Take full item
                total_value += val[idx];
                remaining_capacity -= wt[idx];
            }
            else {
                // Take fractional part
                total_value += ratio * remaining_capacity;
                break; // Knapsack full
            }
        }
        
        // Round to 6 decimal places as required
       return round(total_value * 1e6) / 1e6;
    }
};
