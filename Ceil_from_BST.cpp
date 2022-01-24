/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans=INT_MAX;
    auto curr=node;
    while(1){
        if(curr->data==x){
            ans=x; break;
        }
        if(curr->data>x) ans=min(ans,curr->data);
        if((curr->data>x)&&(curr->left!=NULL)){
            curr=curr->left; continue;
        }
        if((curr->data<x)&&(curr->right!=NULL)){
            curr=curr->right; continue;
        }
        break;
    }
    if(ans==INT_MAX) return -1;
    return ans;
}