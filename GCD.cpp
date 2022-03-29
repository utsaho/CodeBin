#include <bits/stdc++.h>
#define     ed          '\n'
#define     UTSHO       ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define     OJ \
freopen("in.txt", "r", stdin); \
freopen("out.txt", "w", stdout);
using namespace std;

//recursive
int find_GCD(int a, int b){
    if(b==0) return a;
    else return find_GCD(b, a%b);
}

//non-recursive
int Find_GCD(int a, int b){
    if(a>b) swap(a, b);
    while(b>0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    UTSHO;
    // OJ;
    int a, b;
    cin>>a>>b;
    int gcd = Find_GCD(a, b);
    int LCM = a*(b/find_GCD(a, b));
    cout<<"GCD: "<<gcd<<ed;
    cout<<"LCM: "<<LCM<<ed;
    return 0;
}