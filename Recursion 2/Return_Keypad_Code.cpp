Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n. Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
  2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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
        return " ";
    }
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0){
        output[0]="";
        return 1;
    }
    string lastString=keypad(num%10);
    string smallString[10000];
    int smallOutput=keypad(num/10, smallString);
    int lastNumber=lastString.length();
    int k=0;
    for(int i=0;i<lastNumber;i++){
        for(int j=0;j<smallOutput;j++){
            output[k]=smallString[j]+lastString[i];
            k++;
        }
    }return k;
}
