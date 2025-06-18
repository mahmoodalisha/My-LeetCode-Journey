#define ll long long
class Solution {
public:
    int MOD = 1e9+7;
    int binpow (int a, int b){ //binary exponential that is a power b
        int res = 1;
        while(b !=  0){ //then do right shift of b
            if(b&1){//if the last bit of b is set
                res = ((ll)res * a) % MOD;

            }
            a = ((ll)a * a) % MOD;

            b>>=1; //do a right shift of b
        }
        return res;
    }
    int factorial(int num){
        if(num == 0 || num == 1) return 1;
        int res = 1;
        for(int i=2;i<=num; i++){
            res = (ll)(res) * i%MOD;
        }
        return res;
    }
    int modinverse(int a){//will take a number a and give mod inverse
    return binpow(a,MOD-2);
    }
    int invfact(int num) {
        int fac = factorial(num);
        return modinverse(fac);
    }
    int countGoodArrays(int n, int m, int k) {
        int nCr = ( (ll)factorial(n - 1) * invfact(n - k - 1) % MOD * invfact(k) % MOD );
        int power = binpow(m - 1, n - k - 1);
        return ( (ll)nCr * ((ll)m * power % MOD) % MOD ) % MOD;
    }
};

//youtube: eye on AI and DSA by Mitadru dutta