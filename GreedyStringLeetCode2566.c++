class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string max_string = s;

        for(char c : s){
            if(c != '9'){
                for(char& x : max_string){
                    if (x == c){
                        x = '9';   
                    }
                }
                break;
            }
        }
            string min_string = s;
            for(char& x : min_string){
                if(x == s[0])
                x = '0';
            }
        
        return stoi(max_string) - stoi(min_string);
    }
};

//youtube: codestory with MIK

/* 
# Intuition
First, convert the first digit that is not already '9'. This gives the maximum number. This will help in getting a maximum number.
For example, when we get an input like 11891, we can convert first element,to 9 so all the other 1 will also get converted thus we will get a maximum number of 99899, this maximum number will be stored.
To get the minimum number, replace all instances of the first digit in the number with '0', in this way we will get a minimum number. Now we have both our maximum number and our minimum number, 
just find the difference between the two. But converting our given input number to string is the first step.

# Approach
This is a greedy approach. In brute force approach, we needed to iterate again and again, but in greedy approach we are only picking the first best possible number.

# Complexity
- Time complexity:
TC here is O(n)

- Space complexity:
SC here is O(1)



*/