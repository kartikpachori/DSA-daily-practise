class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int count = 0, maxcount = 0;
        int n = arr.size();
        int i = 0, j = 0;
        
        while(i < n){
            if(arr[i] <= dep[j]) { // arrival at departure needs new platform
                count++;
                maxcount = max(maxcount, count);
                i++;
            }
            else{
                count--;
                j++;
            }
        }
        return maxcount;
    }
};
