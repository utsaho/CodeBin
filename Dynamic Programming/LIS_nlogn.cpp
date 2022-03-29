// Write a program to find the LIS and it's length with O(nlogn) time complexity?
// complexity : O(nlog(n))
// space complexity : O(n)
#include <bits/stdc++.h>
#define     tc()        int test_case; cin>>test_case; while(test_case--)
#define     cout(a)     cout<<a<<ed
#define     ed          '\n'
#define     UTSHO       ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define     OJ \
freopen("in.txt", "r", stdin); \
freopen("out.txt", "w", stdout);
using namespace std;

int main() {
	UTSHO;
	OJ;
	int n;
	// cout<<"Enter number of elements: ";
	cin>>n;		// elements of array
	int arr[n+2], lis[n+3];
	// cout<<endl<<"Enter elements: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];	// Value of array
		lis[i+1] = INT_MAX;		// all index of lis is INT_MAX without first index
	}
	lis[0] = INT_MIN;	// initializing first index of lis array is INT_MIN
	for(int i=0; i<n; i++){
		int idx = upper_bound(lis, lis+n+1, arr[i]) - lis;	// get index of lis array, complexity log2(n)
		cout<<idx<<endl;
		if(arr[i]>lis[idx-1] && arr[i]<lis[idx]){	// if i'th index of array less then idx'th index of lis array
													// and greater then idx-1'th index of lis array
			lis[idx] = arr[i];
		}
	}
	cout<<endl;
	int len = 0;
	for(int i=n; i>=0; i--){	// we will find value from last index that if not INT_MAX
		if(lis[i]!=INT_MAX){	// if INT_MAX not found
			len = i;	// this is the length of LIS;
			break;
		}
	}
	for(int i=0; i<=n; i++){
		cout<<lis[i]<<endl;
	}
	cout<<endl<<"LIS length: "<<len<<endl<<endl;
	return 0;
}
