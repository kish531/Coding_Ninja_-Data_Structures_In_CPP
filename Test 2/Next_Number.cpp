Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).

/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

Node* reverse(Node* head){
    Node* temp=head;
    if(head->next){
        head=reverse(temp->next);
        temp->next->next=temp;
        temp->next=NULL;
    }return head;
}

Node* NextLargeNumber(Node *head) {
    head=reverse(head);
    Node* ptr=head, *prev=NULL;
    int carry=1, num;
    while(ptr){
        num=(ptr->data + carry)%10;
        carry=(ptr->data + carry)/10;
        ptr->data=num;
        prev=ptr;
        ptr=ptr->next;
    }
    if(carry){
        Node* newNode= new Node(carry);
        prev->next=newNode;
    }return reverse(head);
}
