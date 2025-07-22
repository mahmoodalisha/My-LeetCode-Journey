//TC: O(log²n)

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = getHeight(root->left);  // left wali height
        int rightHeight = getHeight(root->right); // right wali height

        if (leftHeight == rightHeight) {
            // left subtree full hai
            return (1 << leftHeight) + countNodes(root->right); //Left subtree full hai → usme 2^leftHeight nodes honge to Right subtree mein kitne nodes hain? → use recursively count karo
        } else {
            // right subtree full hai
            return (1 << rightHeight) + countNodes(root->left);
        }
    }

    int getHeight(TreeNode* node) {
        int h = 0; //	Height counter
        while (node) {
            h++; //	Ek level aur badhao
            node = node->left; // Sirf leftmost path pe jao
        }
        return h;
    }
};

//1 << n  →  iska matlab hai:  2^n

/*
| Expression | Binary | Result |
| ---------- | ------ | ------ |
| 1 << 0     | 0001   | 1      |
| 1 << 1     | 0010   | 2      |
| 1 << 2     | 0100   | 4      |
| 1 << 3     | 1000   | 8      |
| 1 << 4     | 10000  | 16     |

    1
   / \
  2   3
 / \  /
4  5 6

Let’s dry-run from root = 1:

leftHeight = getHeight(2) → goes like 2 → 4 → NULL → height = 2
rightHeight = getHeight(3) → goes like 3 → 6 → NULL → height = 2
Since both heights equal → Left subtree is perfect → 2^2 = 4 nodes (including root 2, 4, 5)
Ab right subtree ke liye countNodes(root->right) (which is subtree rooted at 3)
Ab firse wohi logic lagta hai root = 3, uske left/right heights compare karte hain.

Maan lo kisi complete binary tree ki height = 3 hai
Toh agar leftHeight = 3, toh nodes honge:
(1 << 3) - 1 = 2^3 - 1 = 8 - 1 = 7 nodes

Similarly
leftHeight = 4;
1 << 4 = 2^4 = 16
(1 << 4) - 1 = 15

*/