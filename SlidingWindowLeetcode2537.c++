class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {      //left and right is my sliding window
            unordered_map<int, long long> freq; // Frequency map
            long long pairCount = 0; // pairCount sirf ek number hai jo track karta hai Current window ke andar total (i, j) pairs kitne hain? kitne (i, j) pairs hain jisme nums[i] == nums[j] & i < j
            long long ans = 0; // Final answer (good subarrays count)
            int left = 0; // Left pointer of the window
    
            for (int right = 0; right < nums.size(); right++) {  /* nums = [3, 1, 4, 3, 2, 2, 4] Maan lo abhi tumhare sliding window me ye elements hain: Window = [3, 1, 4, 3] Toh freq map hoga: freq = {
      3: 2,   // 3 do baar aaya
      1: 1,   // 1 ek baar aaya
      4: 1    // 4 ek baar aaya freq se hum pairs bana rahe hai. freq ka use hum pairs track karne ke liye karte hain — matlab, har element kitni baar aa chuka hai window ke andar, yeh pata karte hain.
    }
    */
                pairCount += freq[nums[right]];   
                /* Let’s say current window: [4, 3, 4] 
                Frequency map: 4 → 2, 3 → 1
                nums[right] = 4*/

                freq[nums[right]]++;
    
                // Shrink the window from left while we have enough pairs
                while (pairCount >= k) {
                    // All subarrays from left to end of array with this window are good
                    ans += (nums.size() - right);
    
                    // Shrink the window: remove nums[left]
                    freq[nums[left]]--;
                    // Removing this element decreases the pairCount by how many duplicates it had left
                    pairCount -= freq[nums[left]];
                    left++;
                }
            }
    
            return ans;
        }
    };  
    
    /* matlab mera first step hai ek window ko pakad ke chalna, yahi window mera sub array kehlata hai, usi me saare pairs ko count karna hai, phir khatam kahani, ab phir se ek naye window ko pakadna, aur same kaam repeat karna phir freq map ka kaam subarrays me elements ke frequencies ko track karna hai, taaki tum efficiently pairs count kar sako jab window slide hota hai. aur last me ans se humlog saare sub arrays ko count karte hai*/  
    
    /* given nums = [1, 2, 1, 1]
    k = 2
    Hum sliding window approach laga rahe hain, aur shuru se right pointer move karega.
    Step-by-step with freq map and pairCount:
    ✅ Step 1: right = 0 → nums[right] = 1
    freq[1] = 0 (abhi tak window me nahi aaya tha)
    pairCount += 0 → total = 0
    Now update freq: freq[1]++ → freq[1] = 1
    
    ✅ Step 2: right = 1 → nums[right] = 2
    freq[2] = 0
    pairCount += 0 → still total = 0
    freq[2]++ → freq[2] = 1
    
    ✅ Step 3: right = 2 → nums[right] = 1
    freq[1] = 1 (1 already ek baar aa chuka hai)
    pairCount += 1 → total = 1
    kyunki naya 1 ek pair banayega previous 1 ke saath
    freq[1]++ → freq[1] = 2
    
    ✅ Step 4: right = 3 → nums[right] = 1
    freq[1] = 2 (1 abhi do baar aa chuka hai)
    pairCount += 2 → total = 3
    kyunki naya 1 banayega:
    Pair with first 1
    Pair with second 1
    freq[1]++ → freq[1] = 3 */
    

