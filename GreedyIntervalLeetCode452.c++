class Solution {
public:
static bool compare(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int count = 1; //atleast 1 arrow needed
        int lastEnd = points[0][1]; // Place the first arrow at the end of the first balloon

        for (int i = 1; i < points.size(); ++i){
            if(points[i][0]>lastEnd){ //If the start of the current balloon is after the last arrow's coverage (lastEnd), we need a new arrow
                count++; //increment the count of arrows
                lastEnd = points[i][1]; // Shoot it at the end of the current balloon
            }
        }
        return count;
    }
};
//same as that of leetcode 435