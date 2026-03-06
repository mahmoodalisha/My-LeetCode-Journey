/*
Example 1:
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.


how to find the absolute difference :

|-14 - (-10)| = |-4| = 4
|-4 - 3| = |-7| = 7


Therefore in Example 2:

| Pair      | Difference |
| --------- | ---------- |
| -14 , -10 | 4          |
| -10 , -4  | 6          |
| -4 , 3    | 7          |
| 3 , 8     | 5          |
| 8 , 19    | 11         |
| 19 , 23   | 4          |
| 23 , 27   | 4          |

*/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        int diff = INT_MAX;

        sort(arr.begin(), arr.end());
        for(int i = 1; i<arr.size(); i++){
            diff = abs(min(diff, arr[i] - arr[i-1]));
        }
        for(int i = 1; i<arr.size(); i++){
            if((arr[i]-arr[i-1])<=diff){
                result.push_back({arr[i-1], arr[i]});
            }
        }
        return result;
    }
};



