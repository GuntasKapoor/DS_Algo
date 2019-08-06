#include <bits/stdc++.h>
using namespace std;

int bfs(vector<int> AdjList[], int src, int dest){
	int visited[100001];
	int dist[100001];
	for(int i = 0; i <=100000; i++){
		visited[i] = 0;
		dist[i] = INT_MAX;
	}
	visited[src] = 1;
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	// int parent[100000];
	// parent[src] = src;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		// cout<<front<<endl;
		if(front == dest){
			return dist[dest];
		}
		for(int i = 0; i < AdjList[front].size(); i++){
			if(!visited[AdjList[front][i]]){
				visited[AdjList[front][i]] = 1;
				q.push(AdjList[front][i]);
				dist[AdjList[front][i]] = dist[front]  + 1;

				// cout<<AdjList[front][i]<<" "<<dist[AdjList[front][i]]<<endl; 
				if(AdjList[front][i] == dest){
				// 	int i = dest;
				// 		while(i!=src){
				// 			cout<<i<<" ";
				// 			i = parent[i];					
							
				// }
				return dist[dest];
			}
		}
	}
	}
	return -1;
	// for(int i = 0; i < AdjList[src].size(); i++){
	// 	cout<<AdjList[src][i]<<" ";
	// }
}


int main() {
	int T;
	cin>>T;
	int arr[100001];
		for(int i = 0; i <= 100000; i++){
			arr[i] = 1;
		}
		for(int i = 2; i <= sqrt(100000); i++){
			if(arr[i]){
				for(int j = i*i; j<=100000; j+=i){
					arr[j] = 0;
				}
			}
		}
		vector<int> AdjList[100001];
		for(int i = 1000; i <= 100000; i++){
			if(arr[i]){
			for(int j = 3; j>=0; j--){
			string s = to_string(i);
			s[j] = '0';
			int lower = stoi(s);
			s[j] = '9';
			int upper = stoi(s);
			int inc = pow(10,3-j);
			for(int k = lower; k<=upper; k+=inc){
				if(arr[k]){
					AdjList[i].push_back(k);
					// AdjList[k].push_back(i);
				}
			}
		  }
	     }
		}

	    while(T--){
		int src, dest;
		cin>>src>>dest;

		
		// Get Shortest path from src to dest
		int ans = bfs(AdjList,src,dest);
		if(ans!=-1){
			cout<<ans<<endl;
		}
		else{
			cout<<"Impossible"<<endl;
		}
	}
	return 0;
}