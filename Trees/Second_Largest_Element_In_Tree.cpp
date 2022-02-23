Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.

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
template <typename T>
class HelperSecondLargest{
  	public: 
    TreeNode<T>* largest;
    TreeNode<T>* secondLargest;
    HelperSecondLargest(TreeNode<T>* large, TreeNode<T>* secondLarge){
        largest=large;
        secondLargest=secondLarge;
    }
};

HelperSecondLargest<int>* help(TreeNode<int>* root){
    if(root==NULL){
        return new HelperSecondLargest<int>(NULL, NULL);
    }HelperSecondLargest<int>* ans = new HelperSecondLargest<int>(root,NULL);
    for(int i=0;i<root->children.size();i++){
        HelperSecondLargest<int>* childAns =help(root->children[i]);
        if(ans->largest->data < childAns->largest->data){
            if(childAns->secondLargest==NULL){
                ans->secondLargest=ans->largest;
                ans->largest=childAns->largest;
            }else{
                if(childAns->secondLargest->data>ans->largest->data){
                    ans->largest=childAns->largest;
                    ans->secondLargest=childAns->secondLargest;
                }else{
                    ans->secondLargest=ans->largest;
                    ans->largest=childAns->largest;
                }
            }
        }else{
            if(ans->largest->data!=childAns->largest->data && (ans->secondLargest==NULL || ans->secondLargest->data < childAns->largest->data)){
                ans->secondLargest=childAns->largest;
            }
        }
    }return ans;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    return help(root)->secondLargest;
}
