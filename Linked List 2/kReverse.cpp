Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.

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
class Pair{
    public:
	    Node* head;
      Node* tail;
};

Pair reverse(Node* head){
    if(head==NULL || head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallAns=reverse(head->next);
    smallAns.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallAns.head;
    ans.tail=head;
    return ans;
}

Node *kReverse(Node *head, int k){
    if (head==NULL){
        return head;
    }
    
    int count=1;
    Node* h1=head;
    Node* t1=head;
    while (t1 && count<k){
        t1=t1->next;
        count++;
    }
    Node* h2=NULL;
    if(t1) {
    	h2=t1->next;
    	t1->next=NULL;   
    }
    Node* head2= reverse(h1).head;
    Node* tail2= reverse(h1).tail;
    
    Node* smallHead=kReverse(h2, k);
    tail2->next=smallHead;
    return head2;
}
