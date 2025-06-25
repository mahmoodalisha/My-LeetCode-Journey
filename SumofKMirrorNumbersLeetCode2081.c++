class Solution {
public:
    bool isPalindrome(string baseK){
        int i = 0;
        int j = baseK.length()-1;

        while(i<=j){
            if(baseK[i]!=baseK[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
        }
    string convertToBaseK(long long num, int k){
        if(num == 0){
            return "0";
        }
        string res = "";
        while(num>0){
            res += to_string(num%k);
            num /= k;
        }
        return res;
    }
    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1; //create L length palindrome
        while(n>0){
            int half_length = (L+1)/2; //half length ke jitne digits hai unka palindrome generate karna hai
            long long min_num = pow(10, half_length-1);//us half length ke digits ke jitne minimum nos hai
            long long max_num = pow(10, half_length)-1;

            for(int num = min_num; num<= max_num; num++){
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(second_half.begin(), second_half.end());
                string palindrome = "";
                if(L%2 == 0){ //even length palindrome
                    palindrome = first_half+second_half;
                }
                else{
                    palindrome = first_half+second_half.substr(1);
                }
                //ab base k nikalo
                long long pal_num = stoll(palindrome);
                string baseK = convertToBaseK(pal_num, k);
                if(isPalindrome(baseK)){
                    sum += pal_num; //found one k mirror no
                    n--;
                    if(n == 0) {break;}
                }
            }
            L++;
        }
        return sum;
    }
};