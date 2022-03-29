// Write a program to find the articulation point of any graph?
#include <bits/stdc++.h>
using namespace std;

const int N = 500;
vector<int>adj[N];
vector<int>dis(N, -1), low(N, -1);
vector<int>visit(N);
set<char>articulation_points;
int d;

void DFS(int s, int pa = -1){	// we will receive source node as parent
	visit[s] = 0;
	dis[s] = ++d, low[s] = d;	// Setting discovery time
	int c = 0;		// children of source node
	for(int i=0; i<adj[s].size(); i++){
		int v = adj[s][i];
		if(v!=pa && (visit[v] == 0)){	// we will find the node that is not parent and visited
			low[s] = min(dis[v], low[s]);	// setting low of source node, minimum bitween discovery time of that node and low of source node
		}
		else if(v == pa) continue;		// means dis and low will be same
		else{
			DFS(v, s);
			low[s] = min(low[s], low[v]);
			if(dis[s]<=low[v] && (pa!=-1)){
				articulation_points.insert((char)(s+'A'));	// this is an articulation point
			}
			c++;
		}
	}
	if(c>=2 && pa == -1) articulation_points.insert((char)(s+'A'));		// this is an articulation point
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
		adj[u-'A'].push_back(v-'A');
		adj[v-'A'].push_back(u-'A');
		visit[u-'A'] = 1;	// first node should be visit
		visit[v-'A'] = 1; 	// second node should be visit
	}
	// converting MaxNode into integer because we taken alphabet
	int node = MaxNode-'A'+1;

	for(int i=0; i<=node; i++){
		if(visit[i]){
			DFS(i);
		}
	}
	cout<<"Articulation Points are: ";
	// printing articulation points...
	for(auto points:articulation_points) cout<<points<<' ';
	cout<<endl<<endl;
	return 0;
}
