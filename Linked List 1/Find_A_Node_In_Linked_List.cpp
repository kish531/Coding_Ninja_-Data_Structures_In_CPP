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

int findNode(Node *head, int n){
    Node* temp=head;
    int currIndex=0;
    while(temp!=NULL){
        if(temp->data==n){
            return currIndex;
        }else{
            temp=temp->next;
            currIndex++;
        }
    }return -1;
}
