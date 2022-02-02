Given a singly linked list of integers, sort it using 'Merge Sort.'

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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    if(head1==NULL){
        return head2;
    }if(head2==NULL){
        return head1;
    }
    Node* newHead=NULL;
    Node* newTail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data>head2->data){
            if(newHead==NULL){
                newHead=head2;
                newTail=head2;
                head2=head2->next;
            }else{
                newTail->next=head2;
            	newTail=newTail->next;
            	head2=head2->next;
            }
        }else{
            if(newHead==NULL){
                newHead=head1;
                newTail=head1;
                head1=head1->next;
            }else{
                newTail->next=head1;
            	newTail=newTail->next;
            	head1=head1->next;
            }
        }
    }if(head1!=NULL){
        newTail->next=head1;
    }if(head2!=NULL){
        newTail->next=head2;
    }return newHead;
}

Node *mergeSort(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* mid=midPoint(head);
    Node* head1=head;
    Node* head2=mid->next;
    mid->next=NULL;
    head1=mergeSort(head1);
    head2=mergeSort(head2);
    Node* newHead= mergeTwoSortedLinkedLists(head1, head2);
    return newHead;
}
