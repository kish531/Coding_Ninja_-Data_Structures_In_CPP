Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. 
His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.

#include<stack>
int* stockSpan(int *price, int size)  {
    stack<int> s;
    int *output=new int[size];
    s.push(0);
    output[0]=1;
    for(int i=1;i<size;i++){
        if(price[i]<=price[s.top()]){
            output[i]=1;
            s.push(i);
        }else{
            while(s.size()!=0 && price[i]>price[s.top()]){
                s.pop();
            }if(s.size()==0){
                output[i]=i+1;
            }else{
                output[i]=i-s.top();
            }s.push(i);
        }
    }return output;
}
