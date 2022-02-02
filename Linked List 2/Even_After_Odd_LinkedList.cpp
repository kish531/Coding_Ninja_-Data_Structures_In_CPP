For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. 
The relative order of the odd and even terms should remain unchanged.

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

Node *evenAfterOdd(Node *head){
    Node* oddHead=NULL;
    Node* oddTail=NULL;
    Node* evenHead=NULL;
    Node* evenTail=NULL;
    while(head!=NULL){
        if(head->data%2==0){
            if(evenHead==NULL){
                evenHead=head;
                evenTail=head;
                head=head->next;
            }else{
                evenTail->next=head;
                evenTail=evenTail->next;
                head=head->next;
            }
        }else{
            if(oddHead==NULL){
                oddHead=head;
                oddTail=head;
                head=head->next;
            }else{
                oddTail->next=head;
                oddTail=oddTail->next;
                head=head->next;
            }
        }
    }
    if(oddHead==NULL){
        return evenHead;
    }else if(evenHead==NULL){
        return oddHead;
    }else{
        oddTail->next=evenHead;
        evenTail->next=NULL;
        return oddHead;
    }
}
