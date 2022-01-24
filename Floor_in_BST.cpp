/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    int ans=INT_MIN;
    auto curr=root;
    while(1){
        if(curr->val==X){
            ans=X; break;
        }
        if(curr->val<X) ans=max(ans,curr->val);
        if((curr->val>X)&&(curr->left!=NULL)){
            curr=curr->left; continue;
        }
        if((curr->val<X)&&(curr->right!=NULL)){
            curr=curr->right; continue;
        }
        break;
    }
    if(ans==INT_MIN) return -1;
    return ans;
}