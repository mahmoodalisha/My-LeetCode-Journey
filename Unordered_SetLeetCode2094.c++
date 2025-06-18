class Solution {   
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            unordered_set <int> seen;
            vector <int> result;
            int n = digits.size();
            for (int i = 0; i<n;i++){
                if (digits[i]==0) continue;
                for (int j = i+1; i<n-1; j++){
                    if (digits[j==i]) continue;
                    for (int k = j+1; j<n-2; k++){
                        if (k == i || k == j) continue;
                        int nums = digits[i]*100 + digits[j]*10 + digits[k];
                        if (num %2 == 0 && seen.find(num) == seen.find(end)){
                            seen.insert(num);
                            result.push_back(num);
                        }
                    }
                }
            }
            sort(result.begin(), result.end());
            return result;
        }
    };