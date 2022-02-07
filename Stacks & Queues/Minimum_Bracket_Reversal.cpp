For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. 
The expression will only contain curly brackets.
If the expression can't be balanced, return -1.

#include<stack>
int countBracketReversals(string input) {
    if(input.size() %2!=0){
        return -1;
    }
    stack<int> s;
    for(int i=0;i<input.size();i++){
        if(input[i]=='{'){
            s.push(input[i]);
        }else{
            if(s.size()==0){
                s.push(input[i]);
            }else if (s.size()!=0 && s.top()=='{'){
                s.pop();
            }else if (s.size()!=0 && s.top()=='}'){
                s.push(input[i]);
            }
        }
    }
    int count=0;
    while(!s.empty()){
        char c1=s.top();
        s.pop();
        char c2=s.top();
        s.pop();
        if(c1==c2){
            count++;
        }else{
            count+=2;
        }
    }return count;
}
