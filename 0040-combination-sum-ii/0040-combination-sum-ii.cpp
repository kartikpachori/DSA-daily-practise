class Solution {
    
public:
    void findsum(int idx,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i =idx;i<arr.size();i++){
            if(i>idx &&arr[i-1]==arr[i])continue;
            if(arr[i]>target)break;
            
            ds.push_back(arr[i]);
            findsum(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
            
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        findsum(0,target,candidates,ans,ds);
        return ans;
    }
};



