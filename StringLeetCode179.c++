class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto myComparator = [](int& a, int& b){
            string s1 = to_string(a);
            string s2 = to_string(b);

            return (s1+s2) > (s2+s1);
        };

        sort(nums.begin(), nums.end(), myComparator);

        if(nums[0] == 0){
            return "0";
        }

        string result = "";

        for (int& num : nums){
            result += to_string(num);
        }
        return result;
    }
}; 


//this same question is there in GFG but instead directly nums string is given but here nums is in integer

//do strings ko concatinate karke check karte raho dono me se bada integer kaun bana raha hai then finally ek saath sabko merge kardo

//youtube : codestory with mik