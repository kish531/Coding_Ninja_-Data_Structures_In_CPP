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

Node *deleteNode(Node *head, int pos){
    if(head==NULL){
        return head;
    }
    if(pos==0){
        head=head->next;
        return head;
    }
    Node* temp=head;
    int curr=0;
    while(temp!=NULL && curr<pos-1){
        temp=temp->next;
        curr++;
    }
    if(temp==NULL || temp->next==NULL){
        return head;
    }
    temp->next=temp->next->next;
    return head;
}
