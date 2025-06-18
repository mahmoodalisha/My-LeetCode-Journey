class Solution {
public:
    string multiply(string num1, string num2) {
        // Step 1: Declare the size
        int n1 = num1.size();
        int n2 = num2.size();

        // Step 2: Handle edge cases
        if (n1 == 0 || n2 == 0) return "0";

        // Result vector to store the intermediate multiplication result
        vector<int> result(n1 + n2, 0);

        // Step 3: Traverse from the end of both numbers
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0'); // Multiply the digits

                // Step 4: Determine the positions in the result array
                int p1 = i + j;        // Position for the tens place
                int p2 = i + j + 1;    // Position for the units place

                // Step 5: Add the current multiplication result to the result array
                int sum = mul + result[p2]; // Add the multiplication result
                result[p2] = sum % 10;      // Store the units digit
                result[p1] += sum / 10;     // Add the carry to the tens position
            }
        }

        // Step 6: Convert the result vector to a string, skipping leading zeros
        string product = "";
        for (int num : result) {
            if (!(product.empty() && num == 0)) { // Skip leading zeros
                product += to_string(num);
            }
        }

        // Return "0" if the product is empty (both numbers were "0"), otherwise return the product
        return product.empty() ? "0" : product;
    }
};
