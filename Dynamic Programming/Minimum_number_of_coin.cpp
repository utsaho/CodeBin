#include <bits/stdc++.h>
#define     int         long long
#define     tc()        int test_case; cin>>test_case; while(test_case--)
#define     cout(a)     cout<<a<<ed
#define     ed          '\n'
#define     UTSHO       ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define     OJ \
freopen("in.txt", "r", stdin); \
freopen("out.txt", "w", stdout);
using namespace std;

void solve() {
    int n, m;
    cin>>n>>m;
    int arr[n+1];
    arr[0] = 0;
    for(int i=1; i<=n; i++) cin>>arr[i];
    int table[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 && j==0) table[i][j] = 0;
            else if(i==0 || j==0){
                if(i==0) table[i][j] = INT_MAX;
                else table[i][j] = 0;
            }
            else if(arr[i]<=j){
                table[i][j] = min(table[i-1][j], table[i][j-arr[i]]+1);
            }
            else table[i][j] = table[i-1][j];
        }
    }
    // now you can see the table;
}

int32_t main() {
    UTSHO;
    OJ;
    solve();
    return 0;
}
