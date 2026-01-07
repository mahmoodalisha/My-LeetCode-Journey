/*
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
After doing so, return the array.

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]

*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);

        int maxsofar = -1;
        for(int i = n-1; i>=0; i--){
            result[i] = maxsofar;
            maxsofar = max(maxsofar, arr[i]);
        }
        return result;
    }
};


/* DRY RUN:-
i=5 → result[5]=-1 → maxSoFar=1
i=4 → result[4]=1  → maxSoFar=6
i=3 → result[3]=6  → maxSoFar=6
i=2 → result[2]=6  → maxSoFar=6
i=1 → result[1]=6  → maxSoFar=18
i=0 → result[0]=18 → maxSoFar=18
*/