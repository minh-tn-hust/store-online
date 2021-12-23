#include <bits/stdc++.h>
const int MAX = 1000;
int n,k;
using namespace std;
vector<vector<int>> adjacentEdge(MAX);
int ans = 0;
int vis[MAX];
void DFS(int currentNode, int deep){
	if (deep != k){
		vector<int> nextNodes = adjacentEdge[currentNode];
		for (int i = 0; i < nextNodes.size(); i++){
			if (vis[nextNodes[i]] == 0){
				vis[nextNodes[i]] = 1;
				DFS(nextNodes[i], deep+1);
				vis[nextNodes[i]] = 0;
			}
		}
	} else {
		ans++;
		return;
	}
}

int main(){
	cin >> n>> k;
	int edges;
	cin >> edges;
	for (int i = 0; i < edges; i++){
		int u, v;
		cin >> u >> v;
		adjacentEdge[u].push_back(v);
		adjacentEdge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		memset(vis,0,sizeof(vis));
		vis[i] = 1;
		DFS(i, 0);
	}
	cout << ans/2; 
}
