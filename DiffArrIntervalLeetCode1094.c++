/*
Input : trips = [[2, 1, 5], [3, 3, 7]]
capacity = 4

stamps[1] += 2     // at km 1, 2 passengers get in
stamps[5] -= 2     // at km 5, those 2 get out

stamps[3] += 3     // at km 3, 3 more get in
stamps[7] -= 3     // at km 7, they get out

*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stamps(1001, 0);

        for(vector<int> vec:trips){ //For each trip in trips, you're extracting it into vec
            int people_count = vec[0];
            int start_time = vec[1];
            int end_time = vec[2];

            stamps[start_time] += people_count;
            stamps[end_time] -= people_count;
        }
        
        int total_curr_people = 0;

        for(int i : stamps){
            total_curr_people += i;
            if(total_curr_people>capacity){
                return false;
            }
        }
        return true;
    }
};
//code story with MIK