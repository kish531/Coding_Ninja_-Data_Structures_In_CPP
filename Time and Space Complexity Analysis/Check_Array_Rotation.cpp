int arrayRotateCheck(int *input, int size){
    int minIndex=0;
    for(int i=1;i<size;i++){
        if(input[i]<input[i-1]){
            minIndex=i;
            break;
        }
    }return minIndex;
}
