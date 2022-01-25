int pairSum(int *arr, int n, int num){
    sort(arr, arr+n);
    int i=0, j=n-1, count=0;
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
