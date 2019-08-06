#include <bits/stdc++.h>
using namespace std;

int Bfs(vector<int> *AdjList, int start,int f, int dest){
	int *visited = new int[f + 1];
	fill(visited, visited + f + 1, 0);
	visited[start] = 1;
	int *dist = new int[f + 1];
	fill(dist, dist + f + 1, 0);
	dist[start] = 0;
	
	queue<int> q;
	q.push(start);
	
	while(!q.empty()){
		int front = q.front();
		q.pop();
		if(front == dest){
			return 0;
		}
		for(int i = 0; i < AdjList[front].size(); i++){
			if(!visited[AdjList[front][i]]){
				visited[AdjList[front][i]] = 1;
				dist[AdjList[front][i]] = dist[front] + 1;
				q.push(AdjList[front][i]);
				if(AdjList[front][i] == dest){
					return dist[dest];
				}
			}
		}
}
return -1;
}


int main() {
	int f,s,g,u,d;
	cin>>f>>s>>g>>u>>d;
	
	vector<int> *AdjList = new vector<int>[f + 1];
	for(int i = 1; i <= f; i++){
		if(i - d>=1){
			AdjList[i].push_back(i-d);
		}
		if(i + u<=f){
			AdjList[i].push_back(i + u);
		}
	}
	int ans = Bfs(AdjList, s, f, g);
	if(ans == -1){
		cout<<"use the stairs"<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}