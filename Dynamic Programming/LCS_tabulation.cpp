//  Write a program to find the LCS string using tabulation method. 

#include <bits/stdc++.h>
#define     cout(a)     cout<<a<<ed
#define     ed          '\n'
using namespace std;
const int N = 1e2, M = 1e2;
int LCS[N][M];

void PrintTable(int n, int m){
	cout<<ed;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++) cout<<LCS[i][j]<<" ";
		cout<<ed;
	}
}

void LongestCommonSubsequence() {
	string large, small;
	cout<<"Enter string 1: ";
	cin>>small;
	cout<<"Enter string 2: ";
	cin>>large;
	if(large.length()<small.length()){
		string temp = small;
		small = large; large = temp;
	}
	int n = small.length(), m = large.length();
	// int LCS[n+1][m+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			if(i==0 || j==0) LCS[i][j] = 0;
			else if(small[i-1] == large[j-1]) LCS[i][j] = (1 + LCS[i-1][j-1]);
			else LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
		}
	}
	cout<<ed;
	cout("LCS Length is: "<<LCS[n][m]);
	string l="";
	while(LCS[n][m]!=0 && m!=0 && n!=0){
		if(LCS[n][m]!=LCS[n-1][m] || LCS[n][m]!=LCS[n][m-1]){
			l = small[n-1] + l;
			n--; m--;
		}
		else if(LCS[n][m] == LCS[n][m-1]) m--;
		else n--;
	}
	cout<<ed;
	cout("LCS string is: "<<l<<ed);
	char option;
	cout<<"Enter 1 to see table or press any key to exit: ";
	cin>>option;
	n = small.length(); m = large.length();
	if(option == '1'){
		PrintTable(n, m);
	}
}

int main() {
	LongestCommonSubsequence();
	return 0;
}
