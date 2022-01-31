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

void printIthNode(Node *head, int i){
    Node *curr=head;
    int count=0;
    while(curr!=NULL){
        if(count==i){
            cout<<curr->data;
        }
            count++;
            curr=curr->next;
    }
}
