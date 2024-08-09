class Solution {
public:
    int numberOfSubstrings(string s) {
      int lastseen[3]={-1,-1,-1};
        int count=0;
        
        for(int i=0;i<s.size();i++){
            lastseen[s[i]-'a']=i;
            count+=1+min({lastseen[0],lastseen[1],lastseen[2]});
        }
        return count;
    }
};