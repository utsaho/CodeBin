//  Write a program to find the selected coins which form the given amount of coin change problem
#include <bits/stdc++.h>
#define     ed          '\n'
using namespace std;

int main() {
	int n, m;
	cout<<"Enter the number of conis: ";
	cin>>n;
	cout<<"Enter total amount: ";
	cin>>m;
	int arr[n+4], table[n+3][m+2];
	arr[0] = 0;
	if(n>1) cout<<"Enter Coins: ";
	for(int i=1; i<=n; i++) cin>>arr[i];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			if(i==0 && j==0) {
				table[i][j] = 0;
			}
			else if(i==0){
				table[i][j] = INT_MAX;
			}
			else if(j==0){
				table[i][j] = 0;
			}
			else if(arr[i]<=j){
				table[i][j] = min(table[i-1][j], table[i][j-arr[i]]+1);
			}
			else table[i][j] = table[i-1][j];
		}
	}
	int selected_coins[m+5] ={0}, c=0;
	while(m>0 && n>0){
		if(table[n-1][m]==table[n][m]){
			n--;
		}
		else{
			selected_coins[c++] = arr[n];
			m -= arr[n];
		}
	}
	sort(selected_coins, selected_coins+c);
	if(c>0){
		cout<<"Selected coins are: {";
		for(int  i=0; i<c; i++){
			if(i+1<c) cout<<selected_coins[i]<<", ";
			else cout<<selected_coins[i]<<"}"<<ed;
		}
	}
	else cout<<"Nothing to select!"<<ed;
	return 0;
}
