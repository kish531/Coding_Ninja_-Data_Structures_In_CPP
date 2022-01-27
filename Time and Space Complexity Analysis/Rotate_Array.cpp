void reverse(int *input, int start, int end){
    if(start>=end){
        return;
    }
    while(start<end){
        std::swap(input[start++], input[end--]);
    }
}

void rotate(int *input, int d, int n){
    reverse(input, 0, n-1);
    reverse(input, 0, n-d-1);
    reverse(input, n-d, n-1);   
}
