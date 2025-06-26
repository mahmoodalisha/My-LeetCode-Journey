class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> count;
        for (int num : arr) count[num]++;

        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        for (int x : arr) {
            if (count[x] == 0) continue; //count[x] → array me x kitni baar aaya hai
            if (count[2 * x] == 0) return false; //count[2*x] → array me x ka double kitni baar aaya hai

            count[x]--;
            count[2 * x]--;
        }

        return true;
    }
};
//TC: O(n log n)