//Level Order Traversal BFS
/*
        1
      /   \
     2     3
    / \     \
   4   5     6

Correct BFS order:

1 → 2 → 3 → 4 → 5 → 6

Now ask yourself:

After visiting 1, how do we remember that 2 and 3 must be visited before 4,5,6?
How BFS uses a queue:

Start with root
queue = [1]
Take front element → visit it
visit 1
queue = []

Add its children to the end
queue = [2, 3]


Take next from front
visit 2
queue = [3]

Add 2’s children
queue = [3, 4, 5]

Notice something important 👀
➡️ Older nodes get processed first
➡️ Newer nodes wait their turn

That is exactly FIFO.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        int level = 1;
        int ans = 0;
        long long Maxsum = LLONG_MIN;

        while(!q.empty()){
            int n = q.size();
            int sum =0;

            for(int i = 0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }

            if(sum>Maxsum){
            Maxsum = sum;
            ans = level;
            }

            level++;
        }
        return ans;
    }
};