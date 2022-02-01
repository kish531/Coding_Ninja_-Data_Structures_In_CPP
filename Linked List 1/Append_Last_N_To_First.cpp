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

Node *appendLastNToFirst(Node *head, int n){
    if(head==NULL || n==0){
        return head;
    }
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    temp=head;
    int curr=0;
    while(curr<(len-n-1)){
        temp=temp->next;
        curr++;
    }
    Node* newHead = temp->next;
    Node* newTemp=newHead;
    while(newTemp->next!=NULL){
        newTemp=newTemp->next;
    }
    newTemp->next=head;
    temp->next=NULL;
    return newHead;
}
