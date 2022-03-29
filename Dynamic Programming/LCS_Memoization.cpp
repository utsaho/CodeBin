#include <bits/stdc++.h>
#define     cout(a)     cout<<a<<ed
#define     ed          '\n'
#define     UTSHO       ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define     OJ \
freopen("in.txt", "r", stdin); \
freopen("out.txt", "w", stdout);
using namespace std;

string A, B;
int const N = 1e2, M = 1e2;
int TABLE[N][M];

int LCS(int i, int j){
	if(A[i] == '\0' || B[j] == '\0'){
		TABLE[i][j] = 0;
		return 0;
	}
	if(A[i] == B[j]){
		if(TABLE[i][j] == -1)
			TABLE[i][j] = LCS(i+1, j+1);
		return ++TABLE[i][j];
	}
	else {
		int a, b;
		if(TABLE[i+1][j] == -1)
			TABLE[i+1][j] = LCS(i+1, j);
		if(TABLE[i][j+1] == -1)
			TABLE[i][j+1] = LCS(i, j+1);
		TABLE[i][j] = max(TABLE[i+1][j], TABLE[i][j+1]);
		return TABLE[i][j];
	}
}

int main() {
	UTSHO;
	OJ;
	memset(TABLE, -1, sizeof(TABLE));
	cin>>A>>B;
	if(A.length()>B.length()) swap(A, B);
	A+='\0'; B+='\0';
	int len = LCS(0, 0);

	cout(TABLE[0][0]);

	// for(int i=0; i<A.length(); i++){
	// 	for(int j=0; j<B.length(); j++){
	// 		cout<<TABLE[i][j]<<' ';
	// 	}
	// 	cout<<ed;
	// }
	return 0;
}
