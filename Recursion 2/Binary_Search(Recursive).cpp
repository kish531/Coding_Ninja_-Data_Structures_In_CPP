Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x. Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format : Line 1 : Array size
  Line 2 : Array elements (separated by space)
  Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output: 3 

/**********SOLUTION**********/

// input - input array
// size - length of input array
// element - value to be searched
int binarySearch(int input[], int element, int start, int end){
    if(start>end){
        return -1;
    }int mid=(start+end)/2;
    if(input[mid]==element){
        return mid;
    }else if (input[mid]<element){
        binarySearch(input, element, mid+1, end);
    }else{
        binarySearch(input, element, start, mid-1);
    }
}

int binarySearch(int input[], int size, int element) {
	  if(size==0){
        return -1;
    }
    if(size==1){
        if(input[0]==element){
            return 0;
        }else{
            return -1;
        }
    }return binarySearch(input, element, 0, size-1);
}
