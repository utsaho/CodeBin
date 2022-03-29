#include <bits/stdc++.h>
#define		int			long long
#define     tc()        int test_case; cin>>test_case; while(test_case--)
#define     cout(a)     cout<<a<<ed
#define     ed          '\n'
#define     UTSHO       ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define     OJ \
freopen("in.txt", "r", stdin); \
freopen("out.txt", "w", stdout);
using namespace std;

// cosins are: 2 1
int coin(int n){
	if(n == 0){
		return 0;
	}
	int a, b;
	if((n-1)>=0){
		a = 1+coin(n-1);
	}
	if((n-2)>=0){
		b = 1+coin(n-2);
	}
	return min(a, b);
}

int32_t main() {
	UTSHO;
	OJ;
	int total;	// toal coin
	cin>>total;
	int ans = coin(total);
	cout(ans);
	return 0;
}
