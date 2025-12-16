/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        unordered_map<int, int> mpp;
        for(int c : arr1){
            mpp[c]++;
        }
        for(int x : arr2){
            while(mpp[x]>0){
                result.push_back(x);
                mpp[x]--;
            }
        }
        vector<int> rest;
        for(auto &it : mpp){
            while(it.second > 0){
                rest.push_back(it.first);
                it.second--;
            } 
        }
        sort(rest.begin(), rest.end());

        for(int c : rest){
            result.push_back(c);
        }
        return result;
    }
};