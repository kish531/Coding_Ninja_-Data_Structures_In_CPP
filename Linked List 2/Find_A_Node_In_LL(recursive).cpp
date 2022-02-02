Given a singly linked list of integers and an integer n, find and return the index for the first occurrence of 'n' in the linked list. -1 otherwise.
Follow a recursive approach to solve this.

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

int findNodeRec(Node *head, int n){
    if(head==NULL){
        return -1;
    }else if (head->data==n){
        return 0;
    }
    int ans=findNodeRec(head->next, n);
    if(ans==-1){
        return -1;
    }return ans+1;
}
