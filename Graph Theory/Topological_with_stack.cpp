// Write a  program to find topological sort of any given graph using stack?

#include <bits/stdc++.h>
using namespace std;

const int N = 500;
vector<int>adj[N];
vector<int>visit(N);
stack<int>store;

void DFS(int s){
	visit[s] = 0;
	for(int i=0; i<adj[s].size(); i++){
		int v = adj[s][i];
		if(visit[v]){
			DFS(v);
		}
	}
	store.push(s);
}
int main() {
	int edge;
	cout<<"Enter number of edges: ";
	cin>>edge;
	cout<<"Enter uppercase Latin alphabet."<<endl;
	char u, v, MaxNode = '@';	// MaxNode will contain maximum node of the graph
	/* 
		firstly, We will take uppercase latin alphabet.
		then convert this alphabet into integer.
		if we would take integer, then nothing to convert!
	 */
	for(int i=0; i<edge; i++){
		cin>>u>>v;
		// Maximum node containing...
		if(u>MaxNode) MaxNode = u;
		if(v>MaxNode) MaxNode = v;
		adj[u-'A'].push_back(v-'A');	// first node is the number of row
		visit[u-'A'] = 1;	// first node should be visit
		visit[v-'A'] = 1; 	// second node should be visit
	}
	// converting MaxNode into integer because we taken alphabet
	int node = MaxNode-'A'+1;
	// Running DFS
	for(int i=0; i<=node; i++){
		if(visit[i]){
			DFS(i);
		}
	}
	cout<<endl<<"Topological sorted list: ";
	while(!store.empty()){
		cout<<(char)(store.top()+'A')<<' ';
		store.pop();
	}
	cout<<endl;
	return 0;
}
