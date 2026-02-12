//asked by Microsoft, Amazon, Easy Level , min-Heap(priority Queue) is used
//according to question, elements sorted order me add hote chale jayenge
//aur hum us sorted order ka kth element chahiye
//min-heap me top me small elements hote hai
//isi liye sabse chote element ko upar se pop kar payenge hum

/*  Heap Size = k
| Step | Operation | Value Added | Heap Before  | Heap After Adding | Removed (if size > 3) | Final Heap   | Returned (kth largest) |
| ---- | --------- | ----------- | ------------ | ----------------- | --------------------- | ------------ | ---------------------- |
| 1    | `add(3)`  | 3           | `[4, 5, 8]`  | `[3, 4, 5, 8]`    | `3`                   | `[4, 5, 8]`  | **4**                  |
| 2    | `add(5)`  | 5           | `[4, 5, 8]`  | `[4, 5, 5, 8]`    | `4`                   | `[5, 5, 8]`  | **5**                  |
| 3    | `add(10)` | 10          | `[5, 5, 8]`  | `[5, 5, 8, 10]`   | `5`                   | `[5, 8, 10]` | **5**                  |
| 4    | `add(9)`  | 9           | `[5, 8, 10]` | `[5, 8, 9, 10]`   | `5`                   | `[8, 9, 10]` | **8**                  |
| 5    | `add(4)`  | 4           | `[8, 9, 10]` | `[4, 8, 9, 10]`   | `4`                   | `[8, 9, 10]` | **8**                  |

*/


class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int num : nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop(); //min element will be popped
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();
        }
            return pq.top(); //yahi valid call hai
    }
};