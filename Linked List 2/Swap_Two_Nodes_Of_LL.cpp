You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.

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

Node *swapNodes(Node *head, int i, int j){
    Node* c1=head;
    Node* p1=NULL;
    for(int a=1;a<=i;a++){
        p1=c1;
        c1=c1->next;
    }
    Node* c2=head;
    Node* p2=NULL;
    for(int a=1;a<=j;a++){
        p2=c2;
        c2=c2->next;
    }
    if(p1!=NULL){
        p1->next=c2;
    }else{
        head=c2;
    }
    if(p2!=NULL){
        p2->next=c1;
    }else{
        head=c1;
    }
    
    Node* temp=c2->next;
    c2->next=c1->next;
    c1->next=temp;
    return head;
}
