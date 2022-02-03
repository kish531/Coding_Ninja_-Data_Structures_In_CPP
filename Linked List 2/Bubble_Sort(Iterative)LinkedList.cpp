Given a singly linked list of integers, sort it using 'Bubble Sort.'

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

Node* swap(Node* ptr1, Node* ptr2){
    Node* temp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = temp;
    return ptr2;
}

int len(Node* head){
    Node* temp = head ;
    int i = 0 ;
    while(temp!=NULL){
        i++;
        temp=temp->next ;
    }
    return i;
}

Node *bubbleSort(Node *head){
    if (head==NULL){
        return head;
    }
    int n=len(head)-1;
	  while(n--){
        Node* prev=NULL;
        Node* curr=head;
        while (curr->next!=NULL){
            if (curr->data>curr->next->data){
                if (prev==NULL){
                    Node* next=curr->next;
                    curr->next=next->next;
                    next->next=curr;
                    prev=next;
                    head=prev;
                }else{
                    Node* next=curr->next;
                    prev->next=next;
                    curr->next=next->next;
                    next->next=curr;
                    prev=next;
                }
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
    }
    return head;
}
