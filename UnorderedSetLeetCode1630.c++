/*
just use the formula of arithmetic progression
arr = [4,6,5]
max = 6 min = 4
a = a+d = 4+1 = 5
a = a+2d = 4+2*1 = 6
a = a+3d

you get all the a's push all this in a hash set
d is the common differene formula of d = (maxelemen+minelement)/totalno.ofelements-1
*/

class Solution {
public:
    bool check(vector<int>& arr){
        int n = arr.size();
        int minElement = INT_MAX;
        int maxElement = INT_MIN;

        unordered_set<int> st;
        for (int &num : arr) {
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
            st.insert(num);
        }
        if((maxElement-minElement) % (n-1) != 0)
            return false; //agar divisible hi nahi hai

        int d = (maxElement-minElement)/(n-1);
        int a = minElement+d;

        while(a<maxElement){
            if(st.find(a) == st.end()){ //agar set me nahi mila end aa gaya
                return false; //set me hai hi nahi
            }
            a += d;
        }
        return true;

    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> result;

        for(int i = 0; i<m;i++){
        int start = l[i];
        int end = r[i];
        vector<int>arr(nums.begin()+start, nums.begin()+end+1);

        bool isAP = check(arr);
        result.push_back(isAP);
        }
        return result;
    }
};

//youtube: code story with MIK