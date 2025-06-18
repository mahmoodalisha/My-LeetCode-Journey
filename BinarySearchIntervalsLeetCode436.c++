//hum jis interval pe khade hai uska right kis interval ke left se equal ya chota hai

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n);
        vector<pair<int, int>> helperarray; // stores {left, original_index}

        //now apply binary search on helper array becoz this helper array contains all the left part of the intervals, pick up the left part of the interval and compare it with the elements in the helper array and return its index with the help of hash map that stores the index of the left part
        for (int i = 0; i < n; i++) {
            helperarray.push_back({intervals[i][0], i}); //intervals[i][0] is the start point of the interval.
        } //i is the original index of that interval in the input array

        
        sort(helperarray.begin(), helperarray.end());

        for (int i = 0; i < n; i++) {
            int target = intervals[i][1]; // We want to find the smallest start >= end of current interval
            int left = 0, right = n - 1;
            int idx = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (helperarray[mid].first >= target) {
                    idx = helperarray[mid].second;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            ans[i] = idx;
        }

        return ans;
    }
};
//youtube: codebix
/*
intervals = [[1,4], [2,3], [3,4]]

Construct helperarray
We extract the starting points and their indices:
If the current interval is [3, 5], 
then target = 5, and you want to find an interval like [5, 7] or [6, 8]
helperarray = [ (1,0), (2,1), (3,2) ]
i = 0 → interval = [1, 4]
target = intervals[0][1] = 4

We want to find the smallest interval whose start ≥ 4.
Run binary search on helperarray:
left = 0, right = 2, idx = -1
➤ 1st iteration
mid = 0 + (2 - 0)/2 = 1
helperarray[1].first = 2, which is < 4 → go right → left = 2
➤ 2nd iteration
mid = 2
helperarray[2].first = 3, which is < 4 → left = 3
Now left > right, exit loop → idx = -1
So, no right interval found → ans[0] = -1
🔁 i = 1 → interval = [2, 3]
target = 3
Want to find smallest interval with start ≥ 3
Run binary search on helperarray:
left = 0, right = 2, idx = -1
➤ 1st iteration
mid = 1
helperarray[1].first = 2 < 3 → left = 2
➤ 2nd iteration
mid = 2
helperarray[2].first = 3 ≥ 3 ✅
So this is a valid candidate → idx = helperarray[2].second = 2
Try to find a better one on the left → right = 1
Now left > right → exit → ans[1] = 2
🔁 i = 2 → interval = [3, 4]
target = 4
Run binary search:
left = 0, right = 2, idx = -1
➤ 1st iteration
mid = 1, helperarray[1].first = 2 < 4 → left = 2
➤ 2nd iteration
mid = 2, helperarray[2].first = 3 < 4 → left = 3
Now left > right → no valid interval → ans[2] = -1
*/

//idx stores the index of the "right interval" (if found).
//If not found (i.e., no interval has start >= end), idx stays -1, so you push -1 in the answer