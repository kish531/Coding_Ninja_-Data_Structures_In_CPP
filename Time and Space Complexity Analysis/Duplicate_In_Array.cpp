int findDuplicate(int *arr, int n){
    int totalSum=(n-2)*(n-1)/2;
    int arrSum=0;
    for(int i=0;i<n;i++){
        arrSum+=arr[i];
    }return arrSum-totalSum;
}
