class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        string prefix = "";
        for (char c : searchWord) {
            prefix += c; 
            vector<string> suggestions;
            auto it = lower_bound(products.begin(), products.end(), prefix);
            for (int i = 0; i < 3 && it + i != products.end(); ++i) {
                string& product = *(it + i);
                if (product.find(prefix) != 0) break;
                suggestions.push_back(product);
            }
            result.push_back(suggestions);
        }
        return result;
    }
};
