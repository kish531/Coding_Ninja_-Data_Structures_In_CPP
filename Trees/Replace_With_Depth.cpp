You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.

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

void helperReplace(TreeNode<int>* root, int depth){
    root->data=depth;
    for(int i=0;i<root->children.size();i++){
        helperReplace(root->children[i], depth+1);
    }
}

void replaceWithDepthValue(TreeNode<int>* root) {
    helperReplace(root, 0);
}
