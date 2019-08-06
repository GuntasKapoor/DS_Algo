#include <bits/stdc++.h>
using namespace std;

int maxDist(vector<int> *AdjList, int N,int start,int &node){
	
	queue<int> q;
	int *visited = new int[N];
	q.push(start);
	visited[start] = 1;
	int *dist = new int[N];
	dist[start] = 0;
	while(!q.empty()){

		int front = q.front();
		q.pop();
		for(int i = 0; i < AdjList[front].size(); i++){
			if(!visited[AdjList[front][i]]){
				visited[AdjList[front][i]] = 1;
				q.push(AdjList[front][i]);
				dist[AdjList[front][i]] = dist[front] + 1;
			}
		}

	}
	int maxDist = INT_MIN;
	for(int i = 0; i < N; i++){
		if(maxDist < dist[i]){
			node = i;
			maxDist = dist[i];
		}
	}
	return maxDist;

}

int main() {
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vector<int> *AdjList = new vector<int>[N];
		for(int i = 0; i < N-1; i++){
			int v1,v2;
			cin>>v1>>v2;
			AdjList[v1].push_back(v2);
			AdjList[v2].push_back(v1);
		}
		int node = 0;
		int ans = maxDist(AdjList, N,0,node);
		ans = maxDist(AdjList,N,node,node);
		if(ans%2 == 0)
			ans = ans/2;
		else
			ans = (ans + 1)/2;
		cout<<ans<<endl;
	}
	return 0;
}
