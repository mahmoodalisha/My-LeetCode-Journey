//LeetCode 451

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int>myfreq;
        for(char c : s){
            myfreq[c]++;
        }

        priority_queue<pair<int, char>>myheap;
        for (auto&[ch, freq] : myfreq){
            myheap.push({freq, ch});
        }

        string result;
        while(!myheap.empty()){
            auto[freq, ch] = myheap.top();
            myheap.pop();
            result += string(freq, ch);
        }
        return result;
    }
};

/*
unordered_map<char, int> freqMap;
for (char c : s) {
    freqMap[c]++;
}
s = "tree"
Loop 1: c = 't' → freqMap['t'] = 1
Loop 2: c = 'r' → freqMap['r'] = 1
Loop 3: c = 'e' → freqMap['e'] = 1
Loop 4: c = 'e' → freqMap['e'] = 2

Step 2: Max Heap (Priority Queue)
Push ('t', 1) → maxHeap: { (1, 't') }
Push ('r', 1) → maxHeap: { (1, 't'), (1, 'r') }
Push ('e', 2) → maxHeap: { (2, 'e'), (1, 'r'), (1, 't') }
Now maxHeap automatically keeps highest frequency on top: Top of heap: (2, 'e')

*/