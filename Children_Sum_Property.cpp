/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int maxval=-1;

void maxvert(BinaryTreeNode < int > * root){
    maxval=max(maxval, root->data);
    if(root->left!=NULL) maxvert(root->left);
    if(root->right!=NULL) maxvert(root->right); 
}

void childsumprop(BinaryTreeNode < int > * root, int vmax) {
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        root->data=vmax; return;
    }
    if(root->left!=NULL){  
        childsumprop(root->left,vmax);
    }
    if(root->right!=NULL){
        childsumprop(root->right,vmax);
    }
    int childcnt=0;
    if(root->left!=NULL) childcnt+=(root->left->data);
    if(root->right!=NULL) childcnt+=(root->right->data);
    root->data=childcnt;
}  

void changeTree(BinaryTreeNode < int > * root) {
    if(root==NULL) return;
    maxvert(root);
    childsumprop(root, maxval);
}  