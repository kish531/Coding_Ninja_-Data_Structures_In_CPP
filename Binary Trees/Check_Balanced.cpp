Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.

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

pair<int,bool> helperBalanced(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,bool>ans;
        ans.first=0;
        ans.second=true;
        return ans;
    }
    pair<int,bool>ans;
    pair<int,bool> ans1=helperBalanced(root->right);
    pair<int,bool> ans2=helperBalanced(root->left);
    if(ans1.second==false || ans2.second==false || abs(ans1.first-ans2.first)>1){
        ans.second=false;
    }else{
        ans.second=true;
    }
    ans.first=max(ans1.first,ans2.first)+1;
    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    pair<int,bool> ans=helperBalanced(root);
    return ans.second;
}
