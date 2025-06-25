//Josephus Problem

class Solution {
public:
    int findWinnerIndex(int n, int k){ //recursion function
        if(n == 1){ //base case, ek hi player bacha hai
            return 0; //array ka index
        }
        int index = findWinnerIndex(n-1, k);
        index = (index+k)%n;//find the original 
        return index;
    }
    
    int findTheWinner(int n, int k) {
        int result = findWinnerIndex(n, k);
        return result + 1;
    }
};

//youtube: code story with MIK