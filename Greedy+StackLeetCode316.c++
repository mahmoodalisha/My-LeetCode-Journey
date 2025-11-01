/*
👉 set is used to keep track of unique characters that are already in the stack.
So yes — technically set already ensures we don’t add duplicates.

But… 😏 that isn’t enough for this problem.
Let’s see why the freq array is also needed.

🧠 Why We Need freq[] (Frequency Array)

When we’re deciding whether to pop a character from the stack,
we must ask a very specific question:

“If I remove this character from the stack now…
can I still find this same character again later in the string?”

If the answer is YES, we can safely pop it.
If the answer is NO, we must keep it — or we’ll lose it forever. 🚫

And to know that, we need to know how many times that character still appears in the future → that’s exactly what the freq[] array tells us!
3️⃣ When Do We Pop from the Stack?

We pop only when:
The current char c is lexicographically smaller than the top of the stack (c < st.top()), AND
The top of the stack will appear again later (freq[st.top()] > 0).

Why?
Because if we pop 'd' and there’s another 'd' later, we can re-add it later —
so we can safely remove the earlier 'd' to get a smaller result.

This is how we get lexicographically smallest order while preserving possible order.
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        unordered_set<char> seen;
        stack<char> mystack;

        for(char c : s){
            freq[c]++;
        }
        //process each character
        for(char c : s){
            freq[c]--; //used one occurrence

            //skip if already in stack
            if(seen.count(c)) continue;

        while(!mystack.empty() && c<mystack.top() && freq[mystack.top()] > 0){
            seen.erase(mystack.top());
            mystack.pop();
        }
        mystack.push(c);
        seen.insert(c);
    }
        string result = "";
        while(!mystack.empty()){
            result = mystack.top() + result;
            mystack.pop();
        }
        return result;
    }
};

/*
🧠 Step 3: Pop kyun karte hain?

👉 Hum chahte hain lexicographically smallest string (dictionary order me chhoti).

Toh jab hum ek naya character dekhte hain (maan lo 'a'),
aur stack ke top me koi bada character (like 'c') hai
jiska frequency future me > 0 hai (matlab wo baad me dobara milega),
toh hum us bade character ko hata dete hain (pop kar dete hain),
kyunki hum usse baad me fir se add kar sakte hain sahi jagah par.

⚙️ Example:

s = "cbacdcbc"
| Step | Char | Stack Before | Action                  | Stack After | Reason                         |
| ---- | ---- | ------------ | ----------------------- | ----------- | ------------------------------ |
| 1    | c    | []           | push                    | [c]         | stack empty                    |
| 2    | b    | [c]          | pop c, push b           | [b]         | b < c and c appears later      |
| 3    | a    | [b]          | pop b, push a           | [a]         | a < b and b appears later      |
| 4    | c    | [a]          | push                    | [a, c]      | ok                             |
| 5    | d    | [a, c]       | push                    | [a, c, d]   | ok                             |
| 6    | c    | [a, c, d]    | skip (already in stack) | [a, c, d]   | seen already                   |
| 7    | b    | [a, c, d]    | pop d, pop c, push b    | [a, b]      | b < d, c and both appear later |
| 8    | c    | [a, b]       | push                    | [a, b, c]   | ok                             |

*/