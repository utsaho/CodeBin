#include <bits/stdc++.h>
using namespace std;

int node, edge, a, b, root, tofind;
const int N = 1000;
int dis[N];		// counting distance from root to other node
bool visit[N], adj[N][N];

void BFS(int s){
	visit[s] = true;		// s has been visited
	dis[s] = 0;
	queue<int>q;
	q.push(s);
	cout<<s<<" ";
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int i=0; i<=node; i++){
			if(!visit[i] && adj[p][i]){		// if not visited and adjancency matrix of p and i is true
				q.push(i);
				dis[i] = dis[p]+1;		// Count of present node distance from past node. 1 is distance of two node
				cout<<i<<" ";
				visit[i] = true;
			}
		}
	}
}

int main() {
	cout<<"Enter maximum node: ";
	cin>>node;		// Maximum number of number for Adjacency Matrix
	cout<<endl<<"Enter Number of edges: ";
	cin>>edge;
	cout<<endl<<"Enter adjacent nodes:"<<endl;
	for(int i=0; i<edge; i++){
		cin>>a>>b;
		adj[a][b] = true;
		adj[b][a] = true;		// For undirected graph
	}
	cout<<endl<<"Enter Root node: ";
	cin>>root;
	cout<<endl<<"Enter Specific node: "; 
	cin>>tofind;
	cout<<endl<<"Result: ";
	BFS(root);		// sending root to BFS function
	cout<<endl;
	cout<<endl<<"Distance of root to "<<tofind<<" is: "<<dis[tofind]<<endl;
	return 0;
}	
