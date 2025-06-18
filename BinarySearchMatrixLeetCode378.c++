/*
| Variable | Meaning                            | Value               |
| -------- | ---------------------------------- | ------------------- |
| `low`    | Minimum value in matrix            | `1`                 |
| `high`   | Maximum value in matrix            | `15`                |
| `mid`    | Value to check using binary search | changes each time   |
| `count`  | How many numbers ≤ mid             | we compare with `k` |
| `k`      | We want the k-th smallest value    | `8`                 |

*/

/*
We do not look for specific rows. Instead, we set:
low = matrix[0][0] = 1 → the smallest value in the matrix
high = matrix[n-1][n-1] = 15 → the largest value in the matrix
So we search in the value range from 1 to 15
*/

// count batata hai:"Is mid se chhote ya barabar kitne numbers hain matrix ke andar?"

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];               // smallest element in matrix eg 1 from the input
        int high = matrix[n - 1][n - 1];      // largest element in matrix eg 15 from the input

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Count how many numbers ≤ mid
            int count = 0;
            int i = n - 1, j = 0;  // start from bottom-left corner eg 12 from the input
            while (i >= 0 && j < n) {
                if (matrix[i][j] <= mid) {
                    count += i + 1;  // all elements in current column up to row i are ≤ mid
                    j++;             // move to next column
                } else {
                    i--;             // move up to smaller elements
                }
            }

            // Adjust binary search based on count
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;  // kth smallest element
    }
};


/*
Suppose mid = 12.
Matrix:
[
  [1,  5,  9],
  [10, 11, 13],
  [12, 13, 15]
]

Matrix ke andar kaun kaun se numbers <= 12 hain?
1, 5, 9, 10, 11, 12  → total 6 numbers
Toh count = 6

Fir hum kya karte hain?
Agar count < k hai → iska matlab humne kam elements cover kiye hain → mid chhoti hai → low = mid + 1
Agar count >= k hai → mid ya usse chhoti value mein answer ho sakta hai → high = mid
Isse hum answer ki taraf zoom in karte jaate hain.

| Mid              | Count (how many ≤ mid?)   | Decision             |
| ---------------- | ------------------------- | -------------------- |
| Agar `count < k` | `mid` too small           | Move `low = mid + 1` |
| Agar `count ≥ k` | `mid` big enough or exact | Move `high = mid`    |
Mid is your guess for the k-th smallest element.
👉 Count tells you how close your guess is.
*/