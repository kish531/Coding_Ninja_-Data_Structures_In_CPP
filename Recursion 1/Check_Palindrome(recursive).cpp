Check whether a given String S is a palindrome using recursion. Return true or false.

Input Format : String S
Output Format : 'true' or 'false'
Constraints : 0 <= |S| <= 1000 where |S| represents length of string S.

Sample Input 1 : racecar
Sample Output 1: true

Sample Input 2 : ninja
Sample Output 2: false

/**********SOLUTION**********/

#include<cstring>
bool helper(char input[], int start, int end){
    if(start>=end){
        return true;
    }if(input[start]==input[end]){
        return helper(input, start+1, end-1);
    }return false;
}

bool checkPalindrome(char input[]) {
	  helper(input, 0, strlen(input)-1);
}
