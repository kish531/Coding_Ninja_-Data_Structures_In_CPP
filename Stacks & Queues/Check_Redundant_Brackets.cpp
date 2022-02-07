For a given expression in the form of a string, find if there exist any redundant brackets or not. 
It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.

#include<stack>
bool checkRedundantBrackets(string expression) {
    stack<char>s;
    for(int i=0;i<expression.size();i++){
        char ch=expression[i];
    }if(ch=='(' or ch=='+' or ch=='-' or ch=='*' or ch=='%'){
        s.push(ch);
    }else if(ch==')'){
        if(s.empty())
          return true;
        if(s.top()=='(')
          return true;
        while(s.size()>0 and s.top()!='(')
          s.pop();
        if(s.size()>0)
          s.pop();
        }
    }return false;
}
