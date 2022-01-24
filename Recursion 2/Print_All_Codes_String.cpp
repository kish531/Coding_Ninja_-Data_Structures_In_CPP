Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format : A numeric string S
Output Format : All possible codes in different lines
Constraints : 1 <= Length of String S <= 10

Sample Input: 1123
Sample Output:
aabc
kbc
alc
aaw
kw

/**********SOLUTION**********/

#include <string.h>
using namespace std;

void print(string input, string output){
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }char ch1=(input[0]-'0'+'a'-1);
    print(input.substr(1), output+ch1);
    if(input.size()>1){
        int int2=(input[0]-'0')*10 + input[1]-'0';
        if(int2>=10 && int2<=26){
        	char ch2=((input[0]-'0')*10 + input[1]-'0')+'a'-1;
        	print(input.substr(2), output+ch2);
        }
    }   
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output="";
    print(input, output);
}
