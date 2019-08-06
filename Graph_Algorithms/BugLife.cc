#include <bits/stdc++.h>
using namespace std;

bool BugLife(vector<int> *AdjList, int N, int *visited, int start, int *color){
	
	for(int i = 0; i < AdjList[start].size(); i++){
		if(!visited[AdjList[start][i]]){
			visited[AdjList[start][i]] = 1;
			color[AdjList[start][i]] = 1 - color[start];
			bool ans = BugLife(AdjList, N, visited, AdjList[start][i], color);
			if(!ans){
				return false;
			}
		}
		else{
			if(color[AdjList[start][i]] == color[start]){
				return false;
			}
		}
	}
	return true;
	
}



int main() {
	int T;
	cin>>T;
	int k = 1;
	while(T--){
		int N, M;
		cin>>N>>M;
		vector<int> * AdjList = new vector<int>[N];
		for(int i = 0; i < M; i++){
			int v1,v2;
			cin>>v1>>v2;
			AdjList[v1 - 1].push_back(v2 -1);
			AdjList[v2 - 1].push_back(v1 - 1);
		}
		int *visited = new int[N];
		bool ans;
		int *color = new int[N];
		fill(visited, visited + N, 0);
		for(int i = 0; i < N; i++){
			if(!visited[i]){
				visited[i] = 1;
				color[i] = 0;
				ans = BugLife(AdjList, N, visited, i,color);
				if(ans == false){
					break;
				}
			}
		}
		cout<<"Scenario #"<<k<<':'<<endl;
		if(!ans){
			cout<<"Suspicious bugs found!"<<endl;
		}
		else{
			cout<<"No suspicious bugs found!"<<endl;
		}
		delete []visited;
		delete [] color;
		k++;
	}
	return 0;
}