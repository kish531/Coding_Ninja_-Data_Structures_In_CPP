For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. 
You just need to construct the tree and return the root.

/***********************************************************
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

BinaryTreeNode<int>* buildTree(int *preorder, int startPre, int endPre, int *inorder, int startIn, int endIn){
    if(startIn>endIn){
        return NULL;
    }
    int rootData = preorder[startPre];
    int rootIndexIn=-1;
    for(int i=startIn;i<=endIn;i++){
        if(inorder[i]==rootData){
            rootIndexIn=i;
            break;
        }
    }
    int leftStartIn = startIn;
    int leftEndIn = rootIndexIn-1;
    int leftStartPre = startPre+1;
    int leftEndPre = leftStartPre + leftEndIn - leftStartIn;
    int rightStartIn = rootIndexIn+1;
    int rightEndIn = endIn;
    int rightStartPre = leftEndPre+1;
    int rightEndPre = endPre;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTree(preorder, leftStartPre, leftEndPre, inorder, leftStartIn, leftEndIn);
    root->right = buildTree(preorder, rightStartPre, rightEndPre, inorder, rightStartIn, rightEndIn);
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    buildTree(preorder, 0, preLength-1, inorder, 0, inLength-1);
}
