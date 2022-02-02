You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' 
Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.

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

Node *skipMdeleteN(Node *head, int M, int N){
    if(M==0 || head==NULL){
        return NULL;
    }
    if(N==0){
        return head;
    }
    Node* temp1=head;
    while(temp1!=NULL){
        for(int i=1;i<M && temp1!=NULL;i++){
            temp1=temp1->next;
        }
        if(temp1==NULL){
            return head;
        }
        Node* temp2=temp1->next;
        for(int i=1;i<=N && temp2!=NULL;i++){
            temp2=temp2->next;
        }
        temp1->next=temp2;
        temp1=temp2;
    }
    return head;
}
