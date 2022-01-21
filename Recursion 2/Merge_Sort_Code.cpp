Sort an array A using Merge Sort. Change in the input array itself. So no need to return or print anything.
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
2 1 5 2 3
Sample Output 2 : 1 2 2 3 5 
  
/**********SOLUTION**********/

void mergeTwoArrays(int input[], int startIndex, int midIndex, int endIndex){
    int i=startIndex, j=midIndex+1, k=0;
    int output[endIndex-startIndex+1];
    while(i<=midIndex && j<=endIndex){
        if(input[i]<=input[j]){
            output[k]=input[i];
            i++, k++;
        }else if (input[i]>input[j]){
            output[k]=input[j];
            k++, j++;
        }
    }
    while(i<=midIndex){
        output[k]=input[i];
        k++, i++;
    }
    while(j<=endIndex){
        output[k]=input[j];
        k++, j++;
    }
    int startIndexForOutput=0;
    for(int a=startIndex;a<=endIndex;a++){
        input[a]=output[startIndexForOutput];
        startIndexForOutput++;
    }
}

void mergeSort(int input[], int startIndex, int endIndex){
    if(startIndex>=endIndex){
        return;
    }
    int midIndex=(startIndex+endIndex)/2;
    mergeSort(input, startIndex, midIndex);
    mergeSort(input, midIndex+1, endIndex);
    mergeTwoArrays(input, startIndex, midIndex, endIndex);
}

void mergeSort(int input[], int size){
    if(size==1){
        return;
    }mergeSort(input, 0, size-1);       
}
