Given a Singly Linked List of integers, delete all the alternate nodes in the list.

/*********************************************************
 
    // Following is the node structure

    class Node {
    public:
        int data;
        Node * next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
    
        ~Node() {
            if(next) {
                delete next;
            }
        }
    };

*********************************************************/

void deleteAlternateNodes(Node *head) {
    if(head==NULL){
        return;
    }Node* temp=head->next;
    if(temp==NULL){
        return;
    }head->next=temp->next;
    deleteAlternateNodes(head->next);
}
