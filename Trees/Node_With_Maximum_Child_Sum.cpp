Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. 
In the sum, data of the node and data of its immediate child nodes has to be taken.

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
#include<climits>
template <typename T>
class MaxClass{
  	public: 
    int sum;
    TreeNode<T>* node;
};

MaxClass<int>* maxSumNodeHelper(TreeNode<int>* root){
    if(root==NULL){
        MaxClass<int>* newClass = new MaxClass<int> ();
        newClass->sum=INT_MIN;
        newClass->node=root;
        return newClass;
    }
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    MaxClass<int>* ans=new MaxClass<int>();
    ans->node=root;
    ans->sum=sum;
    
    for(int i=0;i<root->children.size();i++){
        MaxClass<int>* childClass=maxSumNodeHelper(root->children[i]);
        if(childClass->sum>ans->sum){
            ans=childClass;
        }
    }return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    return maxSumNodeHelper(root)->node;
}
