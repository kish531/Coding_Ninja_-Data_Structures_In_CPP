For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. 
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

BinaryTreeNode<int>* buildTree(int* postorder, int startpost, int endpost, int *inorder, int startin, int endin){
    if(startpost>endpost){
        return NULL;
    }int rootData=postorder[endpost];
    int rootIndexIn=-1;
    for(int i=startin;i<=endin;i++){
        if(inorder[i]==rootData){
            rootIndexIn=i;
            break;
        }
    }
    
    int leftInStart=startin;
    int leftInEnd=rootIndexIn-1;
    int rightInStart=rootIndexIn+1;
    int rightInEnd=endin;
    int leftPostStart=startpost;
    int leftPostEnd=leftInEnd-leftInStart+startpost;
    int rightPostStart=leftPostEnd+1;
    int rightPostEnd=endpost-1;
    
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    root->left=buildTree(postorder, leftPostStart, leftPostEnd, inorder, leftInStart, leftInEnd);
    root->right=buildTree(postorder, rightPostStart, rightPostEnd, inorder, rightInStart, rightInEnd);
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    buildTree(postorder, 0, postLength-1, inorder, 0, inLength-1);
}
