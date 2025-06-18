class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> myfinalinterval;

        if(intervals.size() == 0){
            return myfinalinterval;
        }

        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0]; // start with the first interval

        for(auto& it : intervals){
            if(it[0]<=tempInterval[1]){   //this means you got the overlapping interval
                tempInterval[1] = max(tempInterval[1], it[1]);   //now merge this overlapping interval, the one which is not overlapping we push into the myfinalinterval
            }
            else{
                myfinalinterval.push_back(tempInterval);
                tempInterval = it; // start new interval
            }
        }
        // Don't forget to push the last interval
        myfinalinterval.push_back(tempInterval);
        return myfinalinterval;
    }
};

/*
| Index     | intervals[i] |
| -----     | ------------- |
| 0         | [1, 3]       |
| 1         | [2, 6]       |
| 2         | [8, 10]      |
| 3         | [15, 18]     |
 
 
ye kaam karta hai:

1st iteration: it = [1, 3]
2nd iteration: it = [2, 6]
3rd iteration: it = [8, 10]
4th iteration: it = [15, 18]
youtube: striver
 */