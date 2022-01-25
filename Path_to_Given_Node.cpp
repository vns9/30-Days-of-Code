/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> ans;
int bval;

bool dfs(TreeNode* A){
    if(A==nullptr) return false;
    if(dfs(A->left)||dfs(A->right)||A->val==bval){
        ans.push_back(A->val); return true;
    }
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    ans.clear();
    bval=B;
    dfs(A);
    reverse(ans.begin(),ans.end());
    return ans;
}
