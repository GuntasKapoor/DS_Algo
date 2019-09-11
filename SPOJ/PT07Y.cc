#include <bits/stdc++.h>
using namespace std;


bool DFS(vector<int> AdjList[], int visited[], int start){
	
	if(visited[start]){
		return false;
	}
	visited[start] = 1;
	for(int i = 0; i < AdjList[start].size(); i++){
		bool ans = DFS(AdjList, visited, AdjList[start][i]);
	}
	return true;
}

int main() {
	int N, M;
	cin>>N>>M;
	vector<int> AdjList[10001];
	for(int i = 0; i < M; i++){
		int u, v;
		cin>>u>>v;
		AdjList[u - 1].push_back(v - 1);
		AdjList[v - 1].push_back(u - 1);
	}
	int visited[10001] = {0};
	if(M == N - 1){
	bool ans = DFS(AdjList, visited, 0);
	if(ans){
	int i;
	for(i = 0; i < N; i++){
		if(!visited[i]){
			cout<<"NO"<<endl;
			break;
		}
	}			
	if(i == N){
		cout<<"YES"<<endl;
	}
	}
	else{
		cout<<"NO"<<endl;
	}
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}