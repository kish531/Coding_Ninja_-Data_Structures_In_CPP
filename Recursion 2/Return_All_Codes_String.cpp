Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format : A numeric string
Constraints : 1 <= Length of String S <= 10

Sample Input: 1123
Sample Output:
aabc
kbc
alc
aaw
kw

/**********SOLUTION***********/

#include <string.h>
using namespace std;
int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.size()==0){
        output[0]="";
        return 1;
    }if(input.size()==1){
        output[0]=input[0]-'0'+'a'-1;
        return 1;
    }
    
    int size1=0, size2=0;
    string result1[10000], result2[10000];
    size1=getCodes(input.substr(1), result1);
    if(input.size()>1){
        if((input[0]-'0')*10 + (input[1]-'0')>=10 && (input[0]-'0')*10 + (input[1]-'0')<27){
            size2=getCodes(input.substr(2), result2);
        }
    }
    int k=0;
    for(int i=0;i<size1;i++){
        char first=input[0]-'0'+'a'-1;
        output[k++]=first + result1[i];
    }
    for(int i=0;i<size2;i++){
        char second=(input[0]-'0')*10 + (input[1]-'0')+'a'-1;
        output[k++]=second+result2[i];
    }return k;
}
