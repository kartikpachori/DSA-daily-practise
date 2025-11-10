class Solution {
  public:
    bool isPrime(int n) {
       if(n<3)return false;
       int count =0;
       for(int i=1;i*i<=n;i++){
           if(n%i==0){
               count++;
               if((n/i)!=i)count++;
           }
       }
       
       if(count>2) return false;
       return true;
    }
};
