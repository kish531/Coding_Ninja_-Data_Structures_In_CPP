int pairSum(int *arr, int i, int j, int num){
    int count=0;
    while(i<j){
        if(arr[i]==arr[j] && arr[i]+arr[j]==num){
            count+=(j-i)*(j-i+1)/2;
            return count;
        }else if (arr[i]+arr[j]==num){
            int tempi=i, counti=1;
            while(arr[tempi]==arr[tempi+1]){
                counti++, tempi++;
            }
            int tempj=j, countj=1;
            while(arr[tempj]==arr[tempj-1]){
                tempj--, countj++;
            }
            count=count+ (counti*countj);
            i+=counti;
            j-=countj;
        }else if (arr[i]+arr[j]>num){
            j--;
        }else{
            i++;
        }
    }return count;
}

int tripletSum(int *arr, int n, int num){
    sort(arr, arr+n);
    int triplet=0;
    for(int i=0;i<n;i++){
        triplet+=pairSum(arr, i+1, n-1, num-arr[i]);
    }
    return triplet;
}
