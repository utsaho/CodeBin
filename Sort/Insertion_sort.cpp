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
void insertion_sort(int arr[], int n){
    for(int i=1; i<n; i++){
        if(arr[i-1]>arr[i]){
            int item=arr[i], j=i;
            while(arr[j-1]>item && j>0){
                arr[j]=arr[j-1];
                j--;
            }
            arr[j]=item;
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
	insertion_sort(arr, n); // called counting sort function
}

int32_t main() {
	UTSHO;
	OJ;
	solve();
	return 0;
}

