Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
Return null if tree is empty.

/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
#include<algorithm>
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int>* maxRoot= new TreeNode<int>(root->data);
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* value= maxDataNode(root->children[i]);
        maxRoot->data=max(maxRoot->data, value->data);
    }return maxRoot;
}
