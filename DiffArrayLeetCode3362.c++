class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int qz = queries.size();
        sort(queries.begin(), queries.end());
        vector<int> diff(n + 1, 0);
        int cumsum = 0;
        int j = 0;  //for the next query
        int count = 0;  //how many queries we have used
        priority_queue<int> myheap;

        for (int i = 0; i < n; i++) {
            while (j < qz && queries[j][0] <= i) {  //query ka first index i se chota hona chahiye
                myheap.push(queries[j][1]);   //queries push hongi priority queue me uska end index bhi
                j++;
            }

            while (cumsum + diff[i] < nums[i]) {
                if (myheap.empty()) return -1;

                int a = myheap.top();
                myheap.pop();

                if (a >= i) {
                    diff[i]++;
                    diff[a + 1]--;
                    count++;
                }
            }

            cumsum += diff[i];
        }

        return qz - count;
    }
};
//youtube coding grower