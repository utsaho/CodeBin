#include <bits/stdc++.h>
using namespace std;
/*HELLO, WORLD*/
#define     ll          long long
#define     ull          unsigned long long
#define     pb          push_back
#define     tc()        ll test_case; cin>>test_case; while(test_case--)
#define     ed          '\n'
#define     UTSHO      ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define     OJ \
freopen("in.txt", "r", stdin); \
freopen("out.txt", "w", stdout);

const int n= 100;
int arr[n/32];
vector<int>v;

bool check(int N, int pos){
    return N&(1<<pos);
}

int setB(int N, int pos){
    return N= N|(1<<pos);
}

void sieve(){
    int sq=(int)sqrt(n);
    for(int i=3; i<=sq; i+=2){
        if(check(arr[i/32], i%32) == 0){
            for(int j=i*i; j<=n; j+=(2*i)){
                arr[j/32] = setB(arr[j/32], j%32);
            }
        }
    }
    v.pb(2);
    for(int i=3; i<=n; i+=2){
        if(check(arr[i/32], i%32) == 0){
            v.pb(i);
        }
    }
}
int main() {
    UTSHO;
    // OJ;
    sieve();
    for(auto it:v) cout<<it<<ed;
    return 0;
}
