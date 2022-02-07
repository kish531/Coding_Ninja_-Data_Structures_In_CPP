You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. 
You are required to write a function that reverses the populated stack using the one which is empty.

void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.size()==0){
        return;
    }
    int temp=input.top();
    input.pop();
    reverseStack(input, extra);
    while(input.size()!=0){
        extra.push(input.top());
        input.pop();
    }
    input.push(temp);
    while(extra.size()!=0){
        input.push(extra.top());
        extra.pop();
    }
}
