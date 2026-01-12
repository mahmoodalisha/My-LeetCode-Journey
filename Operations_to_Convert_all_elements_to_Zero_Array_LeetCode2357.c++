class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;

        while(true){ //Each iteration of while(true) = one subtraction operation.
            int smallest_element = INT_MAX; //this here resets the smallest element every time
            for(int num : nums){
            if(num > 0 && num < smallest_element){
                smallest_element = num;
            }
        }

        if(smallest_element == INT_MAX) break; //all zeroes

        //subtract from all non zero elements
        for(int& c : nums){
            if(c > 0){
                c -= smallest_element;
            }
        }
          count++;
    }
        return count;
    }
};