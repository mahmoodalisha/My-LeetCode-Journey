/*
I compute the total sum of the tree first.
Then using postorder DFS, I calculate subtree sums.
For each subtree, I consider it as one part and compute
subtreeSum × (totalSum − subtreeSum) and keep track of the maximum

Step 1️⃣: Compute total sum of the tree

Step 2️⃣: DFS again to compute subtree sums and max product. This must be postorder (children first).

Why? Parent subtree sum depends on children
We must know subtreeSum before calculating product

Step 3️⃣: Update max product for each subtree
*/

//1. First DFS → get total sum
//2. Second DFS → get subtree sums and update max product

class Solution {
public:
    long long totalSum = 0;
    long long best = 0;
    int MOD = 1e9+7;
    
    long long getTotalSum(TreeNode* root){
        if(!root) return 0;
        long long left = getTotalSum(root->left);
        long long right = getTotalSum(root->right);
        return left + right + root->val;
    }

    long long dfs(TreeNode* root){
        if(!root) return 0;
        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subTreeSum = left+right+root->val;

        best = max(best, subTreeSum*(totalSum-subTreeSum));

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root); //first pass
        dfs(root); //second pass
        return best%MOD;
    }
};

/*
compute the total sum of the tree first.
Then using postorder DFS, I calculate subtree sums.
For each subtree, I consider it as one part and compute
subtreeSum × (totalSum − subtreeSum) and keep track of the maximum
 */