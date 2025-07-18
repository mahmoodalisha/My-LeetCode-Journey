class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k == 1) //base case, sirf ek hi character hai
        return 'a';

        int n = operations.size();
        long long len = 1; //starting me word ka length 1 hai
        long long newK = -1; //jo naya k hai -1 se start karlo
        int operationType = -1;

        for(int i = 0; i<n; i++){
            len *=2; //length double hota chala jayega

            if(len >=k){ //jaise hi length greater than equal to k hua matlab ab mujhe k mil sakta hai
            operationType = operations[i];
            newK = k-len/2;
            break;
            }
        }
        char ch = kthCharacter(newK, operations);
        if(operationType == 0){
            return ch; //yahi answer hai
        }
        return ch == 'z' ? 'a' : ch+1;
    }
};

//similar to 3304
//all dry run in my DSA copy