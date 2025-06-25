class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int freq = n/4;

        unordered_map<int, int> mpp;
        for(int& num : arr){
            mpp[num]++;
            if(mpp[num]>freq){
                return num;
            }
        }
        return -1;
    }
};
//25% nikaalne ke liye wo element dekho jo n/4 se zyada baar aa raha hai