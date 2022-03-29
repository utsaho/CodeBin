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
//bubble sort
void bubble_sort(int arr[], int n){
	for(int i=0; i<n; i++){ // first loop for hold a number for maximum
		for(int j=0; j<n-i-1; j++){ // second loop for compare
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}

void solve() {
	int n; cin>>n; // input size of array
	int arr[n+1]; // declaretion of array
	for(int i=0; i<n; i++) {
		cin>>arr[i]; // input elements of array
	}
	bubble_sort(arr, n); // called bubble sort function
}

int32_t main() {
	UTSHO;
	OJ;
	solve();
	return 0;
}
