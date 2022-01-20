Given an integer N, count and return the number of zeros that are present in the given integer using recursion. 
Input Format : Integer N
Output Format : Number of zeros in N
Constraints : 0 <= N <= 10^9

Sample Input 1 : 0
Sample Output 1 : 1

Sample Input 2 : 00010204
Sample Output 2 : 2

Sample Input 3 : 708000
Sample Output 3 : 4

/**********SOLUTION**********/

int countZeros(int n) {
	  if(n==0){
        return 1;
    }if(n<10){
        return 0;
    }int ans=countZeros(n/10);
    if(n%10==0){
        return ans+1;
    }else{
        return ans;
    }
}
