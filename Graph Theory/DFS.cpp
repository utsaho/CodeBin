
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

/* 	
INPUT: 
	10 13
	1 4
	1 2
	4 3
	3 10
	3 9
	3 2
	2 5
	5 6
	5 7
	7 8
	2 7
	8 5
	2 8

OUTPUT: 
	DFS stack retuls: 1 2 3 4 9 10 5 6 7 8 
	DFS recursion retuls: 1 2 3 4 9 10 5 6 7 8 
 */

int node, edge;
const N = 1000;
bool adj[N][N], to_visit[N], recursion_to_visit[N];

void DFS_Recursion(int s){
	recursion_to_visit[s] = false;
	cout<<s<<" ";
	for(int i=0; i<=node; i++){
		if(adj[s][i] && recursion_to_visit[i]){
			DFS_Recursion(i);
		}
	}
}

void DFS_Stack(int s){
	to_visit[s] = false;	// source node has been visited
	stack<int>nodes;		// declaring stack of nodes to store
	nodes.push(s);
	cout<<s<<" ";
	while(!nodes.empty()){
		int h = nodes.top();
		bool not_found = true;		// to ensure that adjacent found or not
		for(int i=0; i<=node; i++){
			if(to_visit[i] && adj[h][i]){
				to_visit[i] = false;
				nodes.push(i);
				cout<<i<<" ";
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
	UTSHO;
	OJ;
	int a, b;	// two adjacent node of same edge
	cin>>node>>edge;
	for(int i=0; i<edge; i++){
		cin>>a>>b;
		adj[a][b] = true;	//there is a edge between node a and b
		adj[b][a] = true;	// if undirected, there is a edge between b and a
		to_visit[a] = true;	// we have to visit a and b node
		to_visit[b] = true;
		recursion_to_visit[a] = true;	// we have to visit a and b node
		recursion_to_visit[b] = true;
	}
	// Solving DFS using stask
	cout<<"DFS stack retuls: ";
	for(int i=0; i<=node; i++){
		if(to_visit[i]){		// if node i is not visited && i node exsist
			DFS_Stack(i);		// sending argument i as a source node
		}
	}
	cout<<ed<<ed;
	// Solving DFS with recursion
	cout<<"DFS recursion retuls: ";
	for(int i=0; i<=node; i++){
		if(recursion_to_visit[i]){
			DFS_Recursion(i);
		}
	}
	cout<<ed<<ed;
	return 0;
}
