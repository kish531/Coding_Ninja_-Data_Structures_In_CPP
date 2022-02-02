For a given singly linked list of integers, find and return the node present at the middle of the list.

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

Node *midPoint(Node *head){
    if(head==NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }return slow;
}
