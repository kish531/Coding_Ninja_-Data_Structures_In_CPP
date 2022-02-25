For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.

/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root->data==x){
        return true;
    }if(root->left!=NULL){
        if(isNodePresent(root->left, x)){
            return true;
        }
    }if(root->right!=NULL){
        if(isNodePresent(root->right, x)){
            return true;
        }
    }return false;
}
