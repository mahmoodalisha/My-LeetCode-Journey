class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> myarray;
        int i = 0;

        while(i<s.length()){
            string mystring = ""; //This way, each time through the while loop, a fresh string group is created
            for(int j = 0; j<k; j++){
                if(i<s.length()){
                    mystring += s[i];
                    i++;
                }
                else{
                    mystring += fill;
                }
            }
            myarray.push_back(mystring);
        }
        return myarray;
    }
};