//two pointer approach
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while(left<right){
            if(height[left]<height[right]){ // matlab left side ki wall chhoti hai so water trapped depends on leftMax only
                if(height[left]>=leftMax){
                    leftMax = height[left];
                }
                else{
                    water += leftMax-height[left];
                }
                left++;
            } else{
                if(height[right] >= rightMax){
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};

//Agar height[left] < height[right], toh left wali side limit hogi (kyunki paani usi taraf se bahar gir sakta hai).


/* Input: height = [0,1,0,2]

| left | height[left] | leftMax (before) | Condition   | Action           | leftMax (after) | water |
| ---- | ------------ | ---------------- | ---------   | ---------------- | --------------- | ----- |
| 0    | 0            | 0                | 0 ≥ 0 ✅   | leftMax = 0      | 0               | 0     |
| 1    | 1            | 0                | 1 ≥ 0 ✅   | leftMax = 1      | 1               | 0     |
| 2    | 0            | 1                | 0 ≥ 1 ❌   | water += 1-0 = 1 | 1               | 1     |
| 3    | 2            | 1                | 2 ≥ 1 ✅   | leftMax = 2      | 2               | 1     |

*/