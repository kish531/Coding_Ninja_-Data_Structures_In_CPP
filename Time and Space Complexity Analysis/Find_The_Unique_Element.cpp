int findUnique(int *arr, int n) {
    int value;
    for(int i=0;i<n;i++){
        value=value^arr[i];
    }return value;
}
