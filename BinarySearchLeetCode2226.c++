class Solution {
public:

    bool canDistribute(vector<int>& candies, int mid, long long k){
        int n = candies.size();
        for(int i = 0; i<n; i++){
            k -= candies[i]/mid; //matlab utne baccho ko mil gaya candies

            if(k<=0){ //matlab saare children ko mil gaya 
                return true;
            }
        }
        return k <= 0;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int maxC = 0;
        long long total = 0;
        for(int i = 0; i<n; i++){
            total += candies[i]; //Saare piles ke candies ko jodo, yani total candies kitni hain wo nikalo if candies = [5,8,6] matlab total is 0+5+8+6=19
            maxC = max(maxC, candies[i]); //saare candies me se max candy pehle assign kar do
        }
        if(total<k){ //Agar tumhare paas kul candies k se kam hain, toh har bache ko 1 candy dena bhi possible nahi hai, toh answer 0 hai
            return 0;
        }
        //binary search from here
        int l = 1;
        int r = maxC;
        int result = 0;

        while(l<=r){
            int mid = l+(r-l)/2;
            if(canDistribute(candies, mid, k)){//agar true aa gaya
            result = mid; //result me mid aa sakta hai but mai increase karne ki koshish karungi
            l = mid+1;
            } else{
                r = mid-1;
            }
        }
        return result;
    }
};