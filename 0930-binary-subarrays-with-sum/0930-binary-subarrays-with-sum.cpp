class Solution {
public:
    int func(vector<int>& nums,int goal){
        int l=0,r=0,sum=0,count=0;
        if(goal<0){
            return 0;
        }
        while(r<nums.size()){
            sum+=nums[r];
            while(goal<sum){
                sum-=nums[l];
                l=l+1;
            }
            count+=r-l+1;
            r++;
            
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal)- func(nums,goal-1);
    }
};