class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
    }
};

//Where k = primes.size(). So index[i] tells us which ugly[] value to multiply with primes[i]
/*
vector<int> ugly(n);          Stores the first n super ugly numbers
ugly[0] = 1;                  By definition, 1 is the first super ugly number

vector<int> index(k, 0);      One pointer per prime index[i] tells which ugly[] index to multiply with primes[i]

vector<int> next(k);          Stores next candidates for each prime next[i] = primes[i] * ugly[index[i]]

DRY RUN
primes = [2, 7, 13, 19]
index  = [0, 0, 0, 0]
ugly   = [1]
next   = [2*1, 7*1, 13*1, 19*1] = [2, 7, 13, 19]



*/