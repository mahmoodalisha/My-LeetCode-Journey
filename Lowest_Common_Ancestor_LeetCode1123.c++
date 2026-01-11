//tree ke sabse depth me chale jaao
//example no.1 mein 7 aur 4 sabse deep me hai, ab ye dono information 2 ko denge ki kitne distance pe hai aur wo kaunse waale node hai
//yahi information hum pair me store karre hai, {meri depth kitni hai, kaunsa node hu mai}
//ab ye info recursively pass hoti rahegi, 2 ye baat jaake 5 ko batayega ki mai LCA hu, phir 7 aur 4 se distance 5 ki 2 ho jayegi
//aese hi 6 bhi calculate karega ki uske left aur right me kuch hai ? phir 6 bhi tahi info pass karega
//5 ko jaankaari dono side se mili hai 6 se aur 2 se, 5 dekhega ki maximum depth kiska hai ? 
//toh 5 ko pata chalega ki maximum depth toh 7 aur 4 se aari hai
//isiliye 2, 7 aur 4 return ho jayega
//5 bhi jaake info 3 ko dega aur ye batayega ki LCA 2 hai , lekin agar 5 ko depth 2 aur 6 se equal milti toh 5 khud ko LCA batate 3 ko jaake
class Solution {
public:
    pair<int, TreeNode*> solve(TreeNode* root){  //{depth, node}
        if(root == NULL) return {0, NULL};
        
        auto left  = solve(root->left);
        auto right = solve(root->right);

        if(left.first == right.first){ //agar depth same hai toh yahi LCA hai
            return { left.first+1, root }; //+1 kyun ki upar badhna hai aur info update karni hai
            }

            else if(left.first>right.first){
                return { left.first+1, left.second }; //left hi mera LCA hai
            }

            else{
                return { right.first+1, right.second }; //right hi mera LCA hai
            }
        }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;
    }
};