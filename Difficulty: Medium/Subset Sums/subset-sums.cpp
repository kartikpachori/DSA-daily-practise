class Solution {
  public:
    void func(vector<int>& arr,int N,vector<int> &result,int idx,int sum){
        if(idx==N){
            result.push_back(sum);
            return;
        }
        
        func(arr,N,result,idx+1,sum);
        func(arr,N,result,idx+1,sum+arr[idx]);
    }
   public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>result;
        int n = arr.size();
        func(arr,n,result,0,0);
        sort(result.begin(),result.end());
        return result;
    }
};