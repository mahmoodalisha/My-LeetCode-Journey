//jo interval newInterval ke saath overlap ho raha hai, usko merge karke return karenge

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> myfinalinterval;

        for(auto& it : intervals){
            if(it[1] < newInterval[0]){  //matlab non overlapping hai
                myfinalinterval.push_back(it);
            }
            else if (it[0] > newInterval[1]){   //ye bhi non overlapping hai
                myfinalinterval.push_back(newInterval);
                newInterval = it;
            }
            else{
                newInterval[0] = min(newInterval[0], it[0]);
                newInterval[1] = max(newInterval[1], it[1]);
            }
        }
        // Add the last remaining interval
        myfinalinterval.push_back(newInterval);

        return myfinalinterval;
    }
};