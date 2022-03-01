For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion and a single space will separate them.

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

void printLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        
        if(front==NULL){
            cout<<endl;
            if(pendingNodes.size()!=0){
                pendingNodes.push(NULL);
            }
        }else{
            cout<<front->data<<" ";
            if(front->left){
                pendingNodes.push(front->left);
            }if(front->right){
                pendingNodes.push(front->right);
            }
        }
    }
}
