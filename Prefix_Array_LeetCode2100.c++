/*
A prefix array (or prefix sum / prefix count / prefix information array) is an array that stores information about all elements up to a certain index, so that you can later answer range-based or condition-based questions quickly.
Think of it as:
“Precomputing partial results so you don’t have to recompute them again and again.”

🧠 Applying the Idea to LeetCode 2100

We used prefix-style computation — but not for sums, for trend tracking.
We computed:
nonInc[i]: how many consecutive non-increasing days end at index i.
nonDec[i]: how many consecutive non-decreasing days start at index i.
Both are built in O(n) using prefix-like logic:
*/

/*
“Time days before and after” explained with example
Let’s say:
security = [5, 3, 3, 3, 5, 6, 2];
time = 2;
We will check each day i to see if it’s a good day.
🧠 For a day to be “good”:
The 2 days before i must be non-increasing.
The 2 days after i must be non-decreasing.
*/

/*
n is the total number of days (security.size()).
To even have one valid day i, we need:
time days before i
time days after i
plus the day itself (i)
So total required days = time (before) + 1 (current) + time (after)
That equals 2 * time + 1.
If your array is shorter than that,
→ there’s no possible day that satisfies both sides.
So we immediately return an empty result vector.
*/


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> result;
        int n = security.size();
        
        if(time == 0){
            for(int i = 0; i<n; i++)
                result.push_back(i);
                return result;
        }
        if(n<2*time+1) return result;

        vector<int> noninc(n,0) , nondec(n,0);
        for(int i = 1; i<n; i++){
            if(security[i]<=security[i-1])
            noninc[i] = noninc[i-1]+1;
        }
        for(int i = n-2; i>=0; i--){
            if(security[i]<=security[i+1])
            nondec[i] = nondec[i+1]+1;
        }
        //now check for good days
        for(int i = time; i<n-time; i++){
            if(noninc[i]>=time && nondec[i]>=time){
                result.push_back(i);
            }
        }
        return result;
    }
};