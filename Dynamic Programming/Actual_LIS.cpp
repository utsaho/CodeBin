// THIS CODE HAS COME MAJOR PROBLEM :( YOU SHOULD CHECK BEFORE USE

// Write a program to find the actual Longest Increasing Subsequence not the LIS length?
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cout<<"Enter number of elements: ";
	cin>>n; // total number of elements
	int arr[n+1], lis[n+1]; 
	cout<<endl<<"Enter Elements: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
		lis[i] = 1; // initialize lis array for self sequence
	}
	int MAX = INT_MIN, M=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[j]<arr[i]){
				lis[i] = max(lis[j]+1, lis[i]);
			}
		}
		if(lis[i]>MAX) {
			MAX = lis[i]; // saving maximum length of sub-sequence from lis array
			M = i; // saving index of maximum length of sub-sequence
		}
	}
	cout<<endl<<"LIS Length: "<<MAX<<endl; // printing maximum length
	cout<<endl<<"LIS Array: ";
	for(int i=0; i<n; i++){
		cout<<lis[i]<<" "; // printing lis array
	}
	cout<<endl;
	int Sequence[M+2], j=M, c=1;
	Sequence[0] = arr[j]; // initializing last value of sub-sequence
	while(j>0){
		if((arr[j-1]<arr[M]) && ((lis[j-1]+1) == lis[M])){
			Sequence[c++] = arr[j-1]; 
			lis[M]--;  // decreasing maximum value of lis array
		}
		j--;
	}
	if(lis[M]>1) Sequence[c++] = arr[0];  // if first elements of array is the part of sub-sequence
	cout<<endl<<"One Sub-Sequence can be: ";
	for(int i=c-1; i>=0; i--){
		cout<<Sequence[i]<<" ";
	}
	cout<<endl<<endl;
	return 0;
}
