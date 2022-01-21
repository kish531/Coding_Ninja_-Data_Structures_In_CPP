Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format : String S
Output format : Modified String
Constraints : 1 <= |S| <= 10^3 where |S| represents the length of string S. 

Sample Input 1 : xaxb
Sample Output 1: ab

Sample Input 2 : abc
Sample Output 2: abc

Sample Input 3 : xx
Sample Output 3: 

/**********SOLUTION**********/

// Change in the given string itself. So no need to return or print anything
#include<cstring>
void removeX(char input[]) {
	  int n=strlen(input);
    if(n==0){
        return;
    }
    if(input[0]=='x'){
        int i=1;
        for(;i<n;i++){
            input[i-1]=input[i];
        }
        input[i-1]='\0';
        removeX(input);
    }removeX(input+1);
}
