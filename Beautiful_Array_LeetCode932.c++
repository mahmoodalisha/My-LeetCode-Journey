//Beautifull array

class Solution {
public:
    vector<int> beautifulArray(int n) {
        // Base case
        if (n == 1) {
            return {1};  //Return Type: The return type of the function beautifulArray is std::vector<int>. The expression {1} creates a std::vector<int> initialized with the single value 1.
        }

        vector<int> res = {1};

        while (res.size() < n) {
            vector<int> temp;
            // For odd numbers: 2*x - 1
            for (int val : res) {
                if (val * 2 - 1 <= n) {
                    temp.push_back(val * 2 - 1);
                }
            }
            // For even numbers: 2*x
            for (int val : res) {
                if (val * 2 <= n) {
                    temp.push_back(val * 2);
                }
            }
            res = temp;
        }

        return res;
    }
};
