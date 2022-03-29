// Write a program to find the Depth First Search traversal of a graph using stack data structure? Use Adjacency List
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int node, edge;
vector<int>adj[N];		// Adjacency List
bool to_visit[N];

void DFS(int s){
	to_visit[s] = false;	// source node has been visited
	stack<int>nodes;		// declaring stack of nodes to store
	nodes.push(s);
	cout<<s<<" ";
	while(!nodes.empty()){
		int h = nodes.top();
		bool not_found = true;		// to ensure that adjacent found or not
		for(int i=0; i<adj[h].size(); i++){		// while i<size of h'th row
			int v = adj[h][i];
			if(to_visit[v]){
				to_visit[v] = 0;
				nodes.push(v);
				cout<<v<<" ";
				not_found = false;
				break;
			}
		}
		if(not_found){		// if adjacent node of h not found
			nodes.pop();
		}
	}
}

int32_t main() {
	int a, b;	// two adjacent node of same edge
	cout<<"Enter maximum Node: ";
	cin>>node;
	cout<<endl<<"Enter Total Edge: ";
	cin>>edge;
	cout<<endl<<"Enter adjacent nodes: "<<endl;
	for(int i=0; i<edge; i++){
		cin>>a>>b;
		adj[a].push_back(b);	// pushing b to a'th row to adjacency list
		adj[b].push_back(a);	// pushing a to b'th row to adjacency list
		to_visit[a] = true;	// we have to visit a and b node
		to_visit[b] = true;
	}
	cout<<endl<<"DFS retuls: ";
	for(int i=0; i<=node; i++){
		if(to_visit[i]){		// if node i is not visited && i node exsist
			DFS(i);		// sending argument i as a source node
		}
	}
	cout<<endl<<endl;
	return 0;
}
