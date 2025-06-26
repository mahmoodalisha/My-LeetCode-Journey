class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int n = meetings.size();
        int daysoff = 0;
        int start = 0;
        int end = 0;

        for(auto &meet : meetings){
            if(meet[0] > end){
                daysoff += meet[0]-end-1; //all dry run in my DSA copy
            }
            end = max(end, meet[1]); //update end
        }
        if(days>end){
            daysoff += days-end;
        }
        return daysoff;
    }
};