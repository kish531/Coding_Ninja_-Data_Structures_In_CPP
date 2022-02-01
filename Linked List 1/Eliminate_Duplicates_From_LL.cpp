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

Node *removeDuplicates(Node *head){
    if(head==NULL){
        return head;
    }
    Node* temp=head;
    Node* prev=head;
    Node* curr=head->next;
    while(curr!=NULL){
        if(prev->data != curr->data){
            prev=curr;
            curr=curr->next;
        }else{
            curr=curr->next;
            prev->next=curr;
        }
    }return head;
}
