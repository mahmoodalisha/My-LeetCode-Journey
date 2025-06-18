class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n+1);
        int i2;
        int i3;
        int i5;

        i2 = i3 = i5 = 1; //they all are pointing to 1st uglt number
        t[1] = 1; //1st ugly number is 1
        for(int i = 2; i<=n; i++){
            int i2uglynumber = t[i2]*2;
            int i3uglynumber = t[i3]*3;
            int i5uglynumber = t[i5]*5;
            int minuglynumber = min({i2uglynumber, i3uglynumber, i5uglynumber});
            t[i] = minuglynumber;
            if(minuglynumber == i2uglynumber)
            i2++; //i2 jis ugly number ko point karra tha, ab wo next ugly number ko point karega
            if(minuglynumber == i3uglynumber)
            i3++;
            if(minuglynumber == i5uglynumber)
            i5++;
        }
        return t[n]; //nth ugly number
    }
};

//t[i] = ith ugly number
//t[n] = nth ugly number
//return t[n]
//youtube: code stroty with MIK