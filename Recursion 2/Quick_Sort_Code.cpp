Sort an array A using Quick Sort. Change in the input array itself. So no need to return or print anything.
Input format : Line 1 : Integer n i.e. Array size
  Line 2 : Array elements (separated by space)
Output format : Array elements in increasing order (separated by space)
Constraints : 1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 : 2 3 4 5 6 8

Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 : 1 2 3 5 7 

/**********SOLUTION**********/
/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		
*/

  int partition(int input[], int start, int end){
    int pivotValue=input[start];
    int count=0;
    for(int i=start+1;i<=end;i++){
        if(input[i]<pivotValue){
            count++;
        }
    }int pivotIndex=count+start;
    std::swap(input[pivotIndex], input[start]);
    int i=start, j=end;
    while(i<pivotIndex && j>pivotIndex){
        if(input[i]<input[pivotIndex]){
            i++;
        }else if (input[j]>=input[pivotIndex]){
            j--;
        }else{
            std::swap(input[i], input[j]);
        }
    }return pivotIndex;
}

void quickSort(int input[], int start, int end){
    if(start>=end){
        return;
    }int partitionIndex=partition(input, start, end);
    quickSort(input, start, partitionIndex-1);
    quickSort(input, partitionIndex+1, end);
}

void quickSort(int input[], int size) {
    quickSort(input, 0, size-1);
}
