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

int Bigmod(int base, int power, int mod){
	// There is two system for power.
	// there is two part of power.
	// if power is even, then the first part will be power/2 and the second part will be power/2
	// if power is odd, then the first part will be base and the second part will be power-1
	// for every time ans should be moded by mod variable
	
	if(power == 0) return 1;	// if power 0, that means value is 1;
	if(power%2==0){
		int FirstTerm = Bigmod(base, power/2, mod);		// First part
		int SecondTerm = Bigmod(base, power/2, mod);	// Second part
		return ((FirstTerm*SecondTerm)%mod);
	}
	else{
		// now the power is odd
		int FirstTerm = base%mod;	// First part
		int SecondTerm = Bigmod(base, power-1, mod);	// Second part
		return ((FirstTerm*SecondTerm)%mod);
	}
}

void solve() {
	int base, power, mod;		// (base^power)%mod
	cin>>base>>power>>mod;
	cout("Base: "<<base<<ed<<"Power: "<<power<<ed<<"Mod "<<mod);		// Printing base, power, mod
	cout("Bigmod is: "<<Bigmod(base, power, mod));
}

int32_t main() {
	UTSHO;
	OJ;
	solve();
	return 0;
}
