#include <bits/stdc++.h>
using namespace std;


void getRanks(vector<int> *AdjList, int indegree[], int N){
	// Kahns Algorihtm
	
	int Ranks[10001];
	priority_queue<int> q;
	for(int i = 0; i < N; i++){
		if(indegree[i] == 0){
			q.push(i);
			Ranks[i] = 1;
		}
	}
	
	while(!q.empty()){
		int front = q.top();
		q.pop();
		
		cout<<Ranks[front]<<" "<<front<<endl<<endl;

		for(int i = 0; i < AdjList[front].size(); i++){
			indegree[AdjList[front][i]]--;
			if(indegree[AdjList[front][i]] == 0){
				q.push(AdjList[front][i]);
				Ranks[AdjList[front][i]] = Ranks[front] + 1;
			}
		}
	}
}


int main() {
	int T;
	cin>>T;
	int s = 1;
	while(T--){
		int N,M;
		cin>>N>>M;
		vector<int> *AdjList = new vector<int>[N + 1];
		int indegree[1001] = {0};
		for(int i = 0; i < M; i++){
			int v1,v2;
			cin>>v2>>v1;
			indegree[v2]++;
			AdjList[v1].push_back(v2);
		}
		cout<<"Scenario #"<<s<<':'<<endl<<endl;
		getRanks(AdjList, indegree, N);
		s++;
	}
	return 0;
}