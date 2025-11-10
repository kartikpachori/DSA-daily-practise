
class Solution {
  public:
    bool armstrongNumber(int n) {
        int sum =0; 
        int num =n;
        while(n>0){
            int lastdigit = n %10;
            sum+=lastdigit*lastdigit*lastdigit;
            n = n/10;
        }
      if(sum==num)return true;
      else{
          return false;
      }
    }
};