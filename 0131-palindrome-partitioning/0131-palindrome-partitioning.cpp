class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        func(0,s,ans,temp);
        return ans;
        }
    void func(int index,string s, vector<vector<string>> &ans,vector<string> &temp){
        if(index==s.size()){
            ans.push_back(temp);
            return ;
        }
        
        for(int i=index;i<s.size();i++){
            if(ispalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                func(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    
    bool ispalindrome(string s, int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
            return true;
        }
    

};
