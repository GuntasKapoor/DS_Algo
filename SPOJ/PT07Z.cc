#include <bits/stdc++.h>
using namespace std;


void DFS(vector<int> AdjList[], int visited[], int start, int dist, int &maxdist, int &maxnode){
	
	visited[start] = 1;
	
	if(dist > maxdist){
		maxdist = dist;
		maxnode = start;
	}
	
	for(int i = 0; i < AdjList[start].size(); i++){
		if(!visited[AdjList[start][i]]){
			DFS(AdjList, visited, AdjList[start][i], dist + 1, maxdist, maxnode);
		}
	}
}

int main() {
	int N;
	cin>>N;
	int M = N - 1;
	vector<int> AdjList[10001];
	for(int i = 0; i < M; i++){
		int u, v;
		cin>>u>>v;
		AdjList[u - 1].push_back(v - 1);
		AdjList[v - 1].push_back(u - 1);
	}
	int visited[10001] = {0};
	int maxnode = 0;
	int maxdist = 0;
	DFS(AdjList, visited, 0, 0, maxdist, maxnode);
	fill(visited, visited + N, 0);
	int dist = 0;
	DFS(AdjList, visited, maxnode, 0, dist, maxnode);
	cout<<dist<<endl;
	return 0;
}