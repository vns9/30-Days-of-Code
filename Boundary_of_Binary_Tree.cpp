/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    vector<int> leftview;
    vector<int> bottomview;
    vector<int> rightview;
    set<TreeNode*> done;

    void dfs(TreeNode* root){
        if(root->left!=NULL){
            if(done.find(root->left)==done.end()){
                dfs(root->left);
            }
        }
        if(root->right!=NULL){
            if(done.find(root->right)==done.end()){
                dfs(root->right);
            }
        }
        if(root->left==NULL&&root->right==NULL){
            bottomview.push_back(root->val);
        }
        done.insert(root);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        // write your code here
        vector<int> tmp;
        if(root==NULL) return tmp;
        dfs(root); TreeNode* curr=root;
        if(root->left!=NULL){
            while(curr->left!=NULL||curr->right!=NULL){
                leftview.push_back(curr->val);
                if(curr->left!=NULL) curr=curr->left;
                else if(curr->right!=NULL) curr=curr->right;
                else break;
            }
        }
        else leftview.push_back(root->val);
        curr=root;
        if(root->right!=NULL){
            while(curr->left!=NULL||curr->right!=NULL){
                rightview.push_back(curr->val);
                if(curr->right!=NULL) curr=curr->right;
                else if(curr->left!=NULL) curr=curr->left;
                else break;
            }
            reverse(rightview.begin(),rightview.end());
            rightview.pop_back();
        }
        vector<int> ans;
        for(auto node: leftview) ans.push_back(node);
        for(auto node: bottomview) ans.push_back(node);
        for(auto node: rightview) ans.push_back(node);
        return ans;
    }
};