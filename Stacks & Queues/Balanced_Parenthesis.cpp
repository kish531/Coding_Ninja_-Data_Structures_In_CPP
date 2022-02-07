For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. 
Brackets are said to be balanced if the bracket which opens last, closes first.

#include<stack>
bool isBalanced(string expression) {
    stack<char> s;
    for(int i=0;i<expression.length();i++){
        if(expression[i]=='('){
            s.push(expression[i]);
        }else if (expression[i]==')'){
            if(s.empty()){
                return false;
            }char topChar=s.top();
            s.pop();
            if(topChar=='(' && expression[i]==')'){
                continue;
            }else{
                return false;
            }
        }
    }return s.empty();
}
