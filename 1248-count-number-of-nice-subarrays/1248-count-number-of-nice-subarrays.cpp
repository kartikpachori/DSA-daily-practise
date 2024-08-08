class Solution {
public:
    int func(vector<int>& nums, int k){
        int r=0,l=0,sum=0,count=0;
        if(k<0){
            return 0;
        }
        while(r<nums.size()){
            sum+=nums[r]%2;
            while(sum>k){
                sum-=nums[l]%2;
                l=l+1;
            }
            count+=r-l+1;
            r++;
        }
        return count;        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return func(nums,k) - func(nums,k-1); 
    }
};