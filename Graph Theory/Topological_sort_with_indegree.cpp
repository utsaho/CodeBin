// Write a program to find the topological sort of any given graph using indegree concept?
#include <bits/stdc++.h>
using namespace std;

const int N = 500;
vector<int>adj[N];
int indegree[N];
vector<int>visit(N);
int node;

void BFS(int s){
	visit[s] = 0;
	for(int i=0; i<adj[s].size(); i++){
		// decreasing indegree of all adjacent node of source node
		--indegree[adj[s][i]];
	}
	for(int i=0; i<=node; i++){
		if(visit[i] && (indegree[i] == 0)){
			cout<<(char)(i+'A')<<' ';
			BFS(i);
		}
	}
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
		we will count indegree using end node.
		if we would take integer, then nothing to convert!
	 */
	for(int i=0; i<edge; i++){
		cin>>u>>v;
		// Maximum node containing...
		if(u>MaxNode) MaxNode = u;
		if(v>MaxNode) MaxNode = v;
		indegree[v-'A']++;	// increasing indegree
		adj[u-'A'].push_back(v-'A');	// first node is the number of row
		visit[u-'A'] = 1;	// first node should be visit
		visit[v-'A'] = 1; 	// second node should be visit
	}
	// converting MaxNode into integer because we taken alphabet
	node = MaxNode-'A'+1;

	cout<<endl<<"Topological sorted list: ";
	for(int i=0; i<=node; i++){
		if(visit[i] && (indegree[i] == 0)){
			cout<<(char)(i+'A')<<' ';
			BFS(i);
		}
	}
	cout<<endl<<endl;
	return 0;
}
