You have been given a queue that can store integers as the data. 
You are required to write a function that reverses the populated queue itself without using any other data structures.

#include<queue>
void reverseQueue(queue<int> &input) {
    if(input.size()==0){
        return;
    }int temp=input.front();
    input.pop();
    reverseQueue(input);
    input.push(temp);
}
