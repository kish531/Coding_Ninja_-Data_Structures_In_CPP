Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.

/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root->right==NULL && root->left==NULL){
        delete root;
        return NULL;
    }if(root->left){
        root->left=removeLeafNodes(root->left);
    }if(root->right){
        root->right=removeLeafNodes(root->right);
    }return root;
}
