#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void DFS(vector<int> AdjList[], int visited[], int start){
	visited[start] = 1;
	for(int i = 0; i < AdjList[start].size(); i++){
		if(!visited[AdjList[start][i]]){
			DFS(AdjList, visited, AdjList[start][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		ll N;
		cin>>N;
		ll M;
		cin>>M;
		vector<int> AdjList[100001];
		for(int i = 0; i < M; i++){
			int u, v;
			cin>>u>>v;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		int ans = 0;
		int visited[100001] = {0};
		for(int i = 0; i < N; i++){
			if(!visited[i]){
				ans++;
				DFS(AdjList, visited, i);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}