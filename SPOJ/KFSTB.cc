#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

ll DFS(vector<int> AdjList[], int visited[], int S, int T, ll dp[]){
	if(S == T){
		return 1;
	}
	if(dp[S] != -1){
		return dp[S];
	}
	
	// visited[S] = 1;
	ll ans = 0;
	for(int i = 0; i < AdjList[S].size(); i++){
		// if(!visited[AdjList[S][i]]){
			ans = ((ans + DFS(AdjList, visited, AdjList[S][i], T, dp)%mod)%mod);
		// }
	}
	dp[S] = ans;
	return ans;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int N,M,S,T;
		cin>>N>>M>>S>>T;
		vector<int> AdjList[10001];
		for(int i = 0; i < M; i++){
			int u, v;
			cin>>u>>v;
			AdjList[u - 1].push_back(v - 1);
		}
		ll dp[10001];
		fill(dp, dp + N, -1);
		int visited[10001] = {0};
		ll ans = DFS(AdjList, visited, S - 1, T - 1, dp);
		cout<<ans<<endl;
	}
	
	return 0;
}