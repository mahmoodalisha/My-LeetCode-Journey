/*
Hum 1 se 9 tak har digit se number banana shuru karenge.
DFS ka matlab — digit by digit jodte jao jab tak number high se chhota ho.
Agar number low ke barabar ya zyada ho — ✅ result me daal do.

1
|
→ 12
   |
   → 123
       |
       → 1234 ❌ (ab 1234 > 1000 → ruk ja)

*/

/*
Another Example 

2
|
→ 23
   |
   → 234
       |
       → 2345 ❌

*/

class Solution {
public:
    void dfs(int num, int low, int high, vector&<int> result){
        if(num>high) return;

        if(num>=low){ //curent number(low) se start karo 
           result.push_back(num);
        }
        int lastdigit = num%10; //last digit build karo
        if(lastdigit>9){
            int nextdigit = num*10+(lastdigit+1);
            dfs(next, low, high, result);
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for(int i = 1; i <= 9; i++){
            dfs(i, low, high, result);
        }
        // result already sorted hota hai, fir bhi sort kar lein safety ke liye
        sort(result.begin(), result.end());
        return result;
    }
};
/*
Hum kya kar rahe hain?
Hum ek number bana rahe hain jisme digits ek ke baad ek aate hain — matlab:

1 → 12 → 123 → 1234 → 12345 ...
Yaani har naya digit = pichla digit + 1

✅ Toh lastDigit + 1 ka matlab:
Agar humare paas number num = 123 hai
To uska last digit kya hai?

int lastDigit = num % 10;  // 123 % 10 = 3
To agla digit kya hona chahiye?
👉 4, kyunki 3 ke baad 4 aata hai

To banega:
int next = 123 * 10 + (3 + 1) = 1230 + 4 = 1234
🔸 Aur Example dekh:
Suppose num = 45


lastDigit = 5
lastDigit + 1 = 6
next = 45 * 10 + 6 = 456

*/