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

void way1(){
	// Complexity O(n2)

	int n; cin>>n;	// number of elements
	int arr[n+1], LIS[n+2];		// arr for store elements and LIS for counting of sequence
	for(int i=0; i<n; i++){
		cin>>arr[i];
		LIS[i] = 1;		// Initilizing LIS with 1 for self counting
	}
	int m = INT_MIN;	// Declaring m for traking maximum value of LIS array that is Longest increasing subsequence
	for(int i=0; i<n; i++){		// this loop for holding a element for comparing with front elements
		for(int j=0; j<i; j++){		// Check first index to i'th index
			if(arr[j]<arr[i]){		// if j'th value of array less then i'th value
				LIS[i] = max(LIS[j]+1, LIS[i]); 	// that means sequence increased by one.
			}
		}
		if(LIS[i]>m) {
			m = LIS[i];
		}

	}
	cout<<m<<ed; 	// Longest Increasing Subsequence Length
}

void way2() {
	// complexity O(nlogn)
	int n; cin>>n; 	// number of elements
	int arr[n+1], LIS[n+3]; 	// arr for storing elements and LIS for counting
	LIS[0] = INT_MIN; 	// operation will be begin brom index 1
	for(int i=0; i<n; i++){
		cin>>arr[i];
		LIS[i+1] = INT_MAX; 	// All of LIS array filled with INT_MAX
	}
	for(int i=0; i<n; i++){
		int index = upper_bound(LIS, LIS+n+1, arr[i]) - LIS;	// complexity logn, will find the self index of LIS array
		if(LIS[index-1]<arr[i] && arr[i]<LIS[index]){
			LIS[index] = arr[i];
		}
	}
	int m = 0;
	for(int i=n; i>0; i--){
		if(LIS[i]!=INT_MAX){
			m = i;
			break;
		}
	}
	cout(m);
}

int32_t main() {
	UTSHO;
	OJ;
	// there are two way of finding longest increasing subsequence 
	way1();		// complexity O(n2)
	way2(); 	// complexity O(nlogn)
	return 0;
}
