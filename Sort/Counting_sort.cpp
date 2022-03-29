// Idea Link: https://www.youtube.com/watch?v=wP_GoeEPB1w

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

void counting_sort(int arr[], int n){
	int M = -1; // to find the maximum value of array for counting array size	
	for(int i=0; i<n; i++){
		if(arr[i]>M){
			M = arr[i]; // if found maximum then save it
		}
	}
	int brr[M+2] = {}; // declare counting array with maximum value size and assign with 0
	for(int i=0; i<n; i++){
		brr[arr[i]]++; // counting frequency of elements in array
	}
	for(int i=1; i<=M; i++){
		brr[i]+=brr[i-1]; // sum of previous frequency of array
	}
	int srt[n+1]; // declareing sorted array
	for(int i=0; i<n; i++){
		srt[brr[arr[i]]-1] = arr[i]; // i'th index of arr array of brr array of srt array equal to i'th index value
		brr[arr[i]]--; // decrease counter value
	}

	for(int i=0; i<n; i++){
		cout<<srt[i]<<" ";
	}

}

void solve() {
	int n; cin>>n; // input size of array
	int arr[n+1]; // declaretion of array
	for(int i=0; i<n; i++) {
		cin>>arr[i]; // input elements of array
	}
	counting_sort(arr, n); // called counting sort function
}

int32_t main() {
	UTSHO;
	OJ;
	solve();
	return 0;
}

