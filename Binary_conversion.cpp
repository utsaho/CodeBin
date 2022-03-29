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

int main() {
//    UTSHO;
    // OJ;
    int n;
    cout<< "Enter Number to find binary number: ";
    cin>>n;
    int i=1;
    while(i*2<=n){
        i*=2;
    }

    cout<< "Maximum Binary series untill: " <<i<<ed<< "Binary numbers are: ";
    while(i>=1){
        if(n/i > 0) cout<< "1";
        else cout<< "0";
        n%=i;
        i/=2;
    }
    return 0;
}

