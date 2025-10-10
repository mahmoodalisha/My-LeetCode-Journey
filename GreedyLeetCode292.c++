class Solution {
public:
    bool canWinNim(int n) {
        if(n%4 != 0) return true;
        else return false;
    }
};
//agar remainder me kuch nahi bachega toh mere paas stone hi nahi bacha last me uthane ke liye toh hum haar jayenge
