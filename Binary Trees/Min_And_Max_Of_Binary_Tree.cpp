For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
Return the output as an object of Pair class, which is already created.

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

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    pair<int, int> ans;
    ans.first=ans.second=root->data;
    if(root->left==NULL && root->right==NULL){
        return ans;
    }
    if(root->left){
        pair<int,int> leftAns=getMinAndMax(root->left);
        ans.first=min(leftAns.first,ans.first);
        ans.second=max(leftAns.second,ans.second);
    }
    if(root->right){
        pair<int,int> rightAns=getMinAndMax(root->right);
        ans.first=min(rightAns.first,ans.first);
        ans.second=max(rightAns.second,ans.second);
    }return ans;
}
