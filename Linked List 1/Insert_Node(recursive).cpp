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

Node* insertNode(Node *head, int i, int data) {
    if(head==NULL){
        return head;
    }
    Node *newNode= new Node(data);
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    Node *x = insertNode(head->next, i-1, data);
    head->next=x;
    return head;
}
