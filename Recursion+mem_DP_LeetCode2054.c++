//starting point ke basis pe sort kardo
//phir binary search lagake dhundo ki kis event ka starting point current event ke ending point se bada hai
//isse for loop lagane ki zrurat nhi padegi TC better ho jayega
//recursion laga ke dekhre hai ki event attend karu ya na karu
//usse max value mil jayegi recursively check karte karte kis event ko attend karu
class Solution {
public:
    int n;
    int t[100001][3]; //solve func ke i aur count ke liye according to the constraint 10 power 5
    int binarySearch(vector<vector<int>>& events, int end){
        int left = 0;
        int right = n-1;
        int result = n;
        while(left<=right){
            int mid = (left+right)/2;
            if(events[mid][0]>end){ //toh valid event hai
                result = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& events, int i, int count){ //kitne maine events attend kiye hai count dekhega
        if(count == 2 || i>=n) return 0; //max do hi event attend kar sakte hai
        if(t[i][count] != -1){
            return t[i][count];
        }
        int next_valid_event = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, next_valid_event, count+1);
        int nottake = solve(events, i+1, count);
        return t[i][count] = max(take, nottake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());
        memset(t, -1, sizeof(t));
        int count = 0; //starting me maine 0 events attend kiye hai
        return solve(events, 0, count);
    }
};

//youtube : code story with MIK