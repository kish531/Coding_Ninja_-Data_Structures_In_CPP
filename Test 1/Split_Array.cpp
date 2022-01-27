Given an integer array A of size N, check if the input array can be splitted in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.
Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.
Return true, if array can be split according to the above rules, else return false.
Note : You will get marks only if all the test cases are passed.
Input Format : Line 1 : Integer N (size of array)
  Line 2 : Array A elements (separated by space)
Output Format : true or false
Constraints : 1 <= N <= 50

Sample Input 1 :
2
1 2
Sample Output 1 : false

Sample Input 2 :
3
1 4 3
Sample Output 2 : true

/**********SOLUTION**********/

bool split(int *input, int size, int start, int leftSum, int rightSum){
    if(start==size){
        if(leftSum==rightSum){
            return true;
        }else{
            return false;
        }
    }
    if(input[start]%3==0){
        rightSum+=input[start];
    }else if (input[start]%5==0){
        leftSum+=input[start];
    }else{
        return split(input, size, start+1, leftSum+input[start], rightSum) || split(input, size, start+1, leftSum, rightSum+input[start]);
    }
    return split(input, size, start+1, leftSum, rightSum);
}

bool splitArray(int *input, int size){
    return split(input, size, 0, 0, 0);    
}
