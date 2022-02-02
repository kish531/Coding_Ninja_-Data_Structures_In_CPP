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

Node *reverseLinkedListRec(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* smallHead=reverseLinkedListRec(head->next);
    Node* temp=smallHead;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return smallHead;   
}

/**********OR**********/

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

Node *reverseLinkedListRec(Node *head){
    return reverse(head).head;
}
