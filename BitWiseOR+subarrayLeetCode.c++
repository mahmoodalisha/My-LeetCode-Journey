class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set <int> prev;
        unordered_set <int> curr;
        unordered_set <int> result;

        for(int i = 0; i<arr.size(); i++){
            for(const int& x : prev){
                curr.insert(x | arr[i]); //prev set me jo hai curr ke saath or karte chale jaao 
                result.insert(x | arr[i]);
            }
            //curr[i] array bhi khud me ek sub array hai
            //uska or bhi khud wo element hoga
            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev = curr; //next element k paas jaungi toh uska prev ko update karna hoga
            curr.clear();
        }
        return result.size();
    }
};
//dry run in my DSA copy youtube : code story with mik