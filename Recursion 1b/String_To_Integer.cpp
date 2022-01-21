Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format : Numeric string S (string, Eg. "1234")
Output format : Corresponding integer N (int, Eg. 1234)
Constraints : 0 <= |S| <= 9 where |S| represents length of string S.

Sample Input 1 : 00001231
Sample Output 1 : 1231

Sample Input 2 : 12567
Sample Output 2 : 12567
  
/***********SOLUTION**********/

#include<cstring>
int stringToNumber(char input[], int n){
	  if(n==0){
        return 0;
    }int b=stringToNumber(input, n-1);
    int a=input[n-1]-'0';
    return b*10+a;
}

int stringToNumber(char input[]) {
    int n=strlen(input);
    return stringToNumber(input, n);
}

/***********OR**********/

#include<cstring>
int pow(int a, int b){
    if(b==0){
        return 1;
    }return a*pow(a,b-1);
}
int stringToNumber(char input[]) {
    int n=strlen(input);
    if(n==0){
        return 0;
    }if(n==1){
        return input[0]-'0';
    }int a=input[0]-'0';
    int b=stringToNumber(input+1);
    return a*pow(10, n-1) + b;
}
