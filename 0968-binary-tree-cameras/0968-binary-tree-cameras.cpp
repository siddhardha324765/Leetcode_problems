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
int ans = 0; 
   int dfs(TreeNode* root){
    if(root == NULL){
        return 2;
    }
    int left = dfs(root->left);
    int right = dfs(root->right);
    if(left==0 or right==0){
        ans++;
        return 1;
    }
    if(left==1 or right==1){
        return 2;
    }
    return 0;
   }
    int minCameraCover(TreeNode* root) {
   //     dfs(root);
         if(dfs(root)==0){
            ans++;
         }

         return ans;
    }
};