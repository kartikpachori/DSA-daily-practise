class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
        int n = start.size();
        vector<pair<int,int>> meetings;
        
        for(int i=0;i<n;i++){
            meetings.push_back({end[i],start[i]});
        }
        
        sort(meetings.begin(),meetings.end());
        
        int count =0;
        int last =-1;
        
        for(auto it:meetings){
            int front = it.second;
            int back = it.first;
            
            if(front >last){
                count++;
                last = back;
            }
        }
        return count;
    }
};