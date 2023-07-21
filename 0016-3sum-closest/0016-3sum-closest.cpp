class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int nearestsum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-1;i++){
         
            int start=i+1;
            int end=nums.size()-1;

            while(start<end){
                int currentsum =nums[start]+nums[end]+nums[i];
                 if(abs(currentsum-target)<abs(nearestsum-target)){
                        nearestsum=currentsum;
                    } 
                if(currentsum<target){
                    start++;
                } else {
                    end--;
                }
            }
          
        }
        return nearestsum;
    }
};


   