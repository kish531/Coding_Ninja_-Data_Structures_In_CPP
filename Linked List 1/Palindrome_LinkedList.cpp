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
#include<stack>
bool isPalindrome(Node *head){
    stack<int> s;
    Node* temp=head;
    while(temp!=NULL){
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        int i=s.top();
        if(i!=temp->data){
            return false;
        }else{
            temp=temp->next;
            s.pop();
        }
    }return true;
}
