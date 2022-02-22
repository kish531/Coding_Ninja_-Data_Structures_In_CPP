Given a generic tree, find and return the height of given tree.

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

int getHeight(TreeNode<int>* root) {
    // Write your code here
    if (root->data==NULL){
        return 0;
    }int maxHeight=0;
    for(int i=0;i<root->children.size();i++){
        int maxHeightChildren=getHeight(root->children[i]);
        if(maxHeightChildren>maxHeight){
            maxHeight=maxHeightChildren;
        }
    }return maxHeight+1;
}
