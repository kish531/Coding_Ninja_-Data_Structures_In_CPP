Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format : Integer n
Output Format : All possible strings in different lines
Constraints : 1 <= n <= 10^6

Sample Input: 23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

/**********SOLUTION**********/

#include <iostream>
#include <string>
using namespace std;

string keypad(int num){
    if(num==2){
        return "abc";
    }if(num==3){
        return "def";
    }if(num==4){
        return "ghi";
    }if(num==5){
        return "jkl";
    }if(num==6){
        return "mno";
    }if(num==7){
        return "pqrs";
    }if(num==8){
        return "tuv";
    }if(num==9){
        return "wxyz";
    }else{
        return "";
    }
}

void printKeypad(int num, string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }int lastNumber=num%10;
    string lastString=keypad(lastNumber);
    for(int i=0;i<lastString.length();i++){
        printKeypad(num/10, lastString[i]+output);
    }
}

void printKeypad(int num){
    printKeypad(num, "");
}
