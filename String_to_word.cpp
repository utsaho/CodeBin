#include <bits/stdc++.h>
#define     int         long long
#define     ull         unsigned long long
#define     tc()        int test_case; cin>>test_case; while(test_case--)
#define     cout(a)     cout<<a<<ed
#define     ed          '\n'
#define     UTSHO       ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define     OJ \
freopen("in.txt", "r", stdin); \
freopen("out.txt", "w", stdout);
using namespace std;

void solve() {
	string s, word; // s string for input and word for using string as single word
	getline(cin, s); // input string
	istringstream holder(s); // get string s to holder
	while(holder>>word){ // while holder not ends
		// now word is each single word of string
		cout(word);
	}
}

int32_t main() {
	UTSHO;
	OJ;
	solve();
	return 0;
}