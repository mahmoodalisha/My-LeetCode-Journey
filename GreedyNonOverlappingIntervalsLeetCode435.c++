/*
✅ Interval: [1,2]
interval[0] = 1, lastEnd = INT_MIN
1 >= INT_MIN → true, so keep this
Set lastEnd = 2

❌ Interval: [1,3]
interval[0] = 1, lastEnd = 2
1 < 2 → overlapping, remove this
Increase count = 1
Don't update lastEnd

✅ Interval: [2,3]
interval[0] = 2, lastEnd = 2
2 >= 2 → no overlap, keep it

Update lastEnd = 3
✅ Interval: [3,4]
interval[0] = 3, lastEnd = 3
3 >= 3 → no overlap, keep it

Update lastEnd = 4
🔚 Final Result:
Removed 1 interval ([1,3])
So, count = 1

input
[[1,2],[2,3],[3,4],[1,3]]
after sorting
[[1,2], [2,3], [1,3], [3,4]]

*/
//TC O(nlogn)

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int count = 0;
        int lastEnd = INT_MAX;
        for(auto& interval : interval){
            if(interval[0]>=lastEnd){
                lastEnd = interval[1];
            }
            else count++;
        }
        return count;
    }
};