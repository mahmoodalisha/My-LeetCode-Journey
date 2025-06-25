class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        if(n == 0) return true;

        for(int i = 0; i<l; i++){
            if(flowerbed[i] == 0){//matlab ye plot khaali hai yaha pe flower laga sakte hai
                bool leftempty = (i == 0) ||  (flowerbed[i-1] == 0); //mai jaha pe khada hu uska left side khaali hai ya nahi
                //(i == 0) mai yaha pe khada hu
                bool rightempty = (i == l-1) || (flowerbed[i+1] == 0);
                if(leftempty && rightempty){
                    flowerbed[i] = 1;
                    n--;

                    if(n == 0)
                    return true;
                }
        
            }
        }
        return false;
    }
};
/*
(i == 0) → Agar mai pehle plot (index 0) pe khada hoon, to mere left mein kuch bhi nahi hai, yaani left side safe hai → true.

(flowerbed[i-1] == 0) → Agar mere left waale plot mein koi phool nahi hai, to bhi safe hai → true.

(i == l - 1) → Yaani mai last plot pe khada hoon, to mere right mein koi plot hai hi nahi → safe hai → true
*/