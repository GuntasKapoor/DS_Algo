// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;

int nodes(vector<int>  AdjList[], int visited[], int start){
    visited[start] = 1;
    int node = 1;
    for(int i = 0; i < AdjList[start].size(); i++){
        if(!visited[AdjList[start][i]]){
            node += nodes(AdjList, visited, AdjList[start][i]);
        }
    }
    return node;
}





int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int T;
cin>>T;
int cnt = 1;
while(T--){
	int N, M;
	cin>>N>>M;
	vector<int> AdjList[100001];
	for(int i = 0; i < M; i++){
	    int u, v;
	    cin>>u>>v;
	    AdjList[u - 1].push_back(v - 1);
	    AdjList[v - 1].push_back(u - 1);
	}
	int visited[100001] = {0};
	int ans = 0;
	int connComp = 0;
	for(int i = 0; i < N; i++){
	    if(!visited[i]){
	        int a = nodes(AdjList, visited, i);
	        connComp++;
	        ans += (a - 1);
	    }
	}
	ans += 2*(connComp - 1);
	cout<<"Case #"<<cnt<<": "<<ans<<endl;
	cnt++;
}

}