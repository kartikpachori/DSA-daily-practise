class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int posint=0;
        int negint=1;
        for(int i =0;i<n;i++){
            if(nums[i]>0){
                ans[posint]=nums[i];
                posint+=2;
            }
            else{
                ans[negint]=nums[i];
                negint+=2;
            }
        }return ans;
    }
};