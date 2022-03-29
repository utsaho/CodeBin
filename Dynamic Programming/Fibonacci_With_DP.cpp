//  Write a program to find the n-th fibonacchi number using Top Down DP approach (Memoization).

#include <bits/stdc++.h>
#define     ull         unsigned long long
#define     cout(result)     cout<<result<<ed
#define     ed          '\n'
using namespace std;
const int N=1e8;

ull arr[N];
int call = 0;

ull fib(ull n){
        call++;
        if(n<=1){
            arr[n] = n;
            if(n!=0 && arr[n-1] == -1) arr[n-1] = fib(n-1);
            return n;
        }
        if(arr[n-2]== -1) arr[n-2] = fib(n-2);
        if(arr[n-1]== -1) arr[n-1] = fib(n-1);
        arr[n]=arr[n-2]+arr[n-1];
        return arr[n];
}

int main() {
    memset(arr, -1, sizeof(arr));
    ull n;
    cout<<"Enter Number of Fibonacchi: ";
    cin>>n;
    fib(n);
    cout(arr[n]);
    int li;
    cout<<ed;
    cout("Option: \n1. List\n0. exit."); cin>>li;
    if(li==1){
        for(ull i=0; i<=n; i++) cout(i<<"'th:  "<<arr[i]);
        cout(ed<<"Total Call: "<<call);
    }
    return 0;
}
