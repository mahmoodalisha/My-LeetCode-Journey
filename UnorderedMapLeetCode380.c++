/*
Let’s say the set has values {10, 20, 30}
nums = [10, 20, 30] sojust store the index of the elements in the map
mp = {
  10: 0,
  20: 1,
  30: 2
}
Calling getRandom() → returns nums[rand() % 3] → any of 10, 20, or 30

For Insertion: when we insert like this 
nums.push_back(val);
mp[val] = nums.size() - 1;
We're doing two things:
Adding val to the end of the vector.
Storing its index (i.e. nums.size() - 1) in the map.

Why is nums.size() - 1 used?
Because when you push_back(val) into a vector, it's added to the last index — which is size - 1.
So we store that index so that later we can:
Quickly find where the value is in nums
Swap it efficiently during remove()
*/

/*
For removal: 
We want to remove val from the set in O(1) time.
But vector does not allow O(1) deletion from the middle.
So we swap the element to be removed with the last element, and then do pop_back().

Initial state:
nums = [10, 20, 30]
mp = {
  10: 0,
  20: 1,
  30: 2
}
Now we want to remove 20 so Get index of 20
int index = mp[20]; // index = 1
int lastElement = nums.back(); // lastElement = 30
nums[index] = lastElement; 

Move lastElement to index of 20
// nums[1] = 30 → nums becomes [10, 30, 20]
now safely remove 20
*/

class RandomizedSet {
public:
    unordered_map<int, int> mpp;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.count(val)) return false;
        nums.push_back(val)
        mpp[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mpp.count(val)) return false;
        int index = mpp[val]; //Now we want to remove 20 so Get index of 20 so int index = mp[20];
        int lastElement = nums.back(); //and get the index of last element
        nums[index] = lastElement; //swap the current element which we want to remove with the last element in the nums
        mpp[lastElement] = index;
        nums.pop_back(); //so that we can safely remove from the nums array
        mpp.erase(val);
    }
    
    int getRandom() {
        int randomized = rand() - nums.size()-1;
        return nums[randomized];
    }
};