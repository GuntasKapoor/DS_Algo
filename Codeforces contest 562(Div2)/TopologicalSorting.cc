#include <bits/stdc++.h>
using namespace std;

void printOrder(vector<int> *AdjList, int indegree[], int N){
	set<int> q;
	for(int i = 1; i <= N; i++){
		if(indegree[i] == 0){
			q.insert(i);
		}
	}
	vector<int> ans;
	while(!q.empty()){
		int front = *(q.begin());
		q.erase(q.begin());
		for(int i = 0; i < AdjList[front].size() ;i++){
				indegree[AdjList[front][i]]--;
				if(indegree[AdjList[front][i]] == 0){
					q.insert(AdjList[front][i]);
			}
		}
		ans.push_back(front);
	}
	if(ans.size() == N){
		for(int i = 0; i < ans.size(); i++){
			cout<<ans[i]<<" ";
		}
	}
	else{
		cout<<"Sandro fails."<<endl;
	}
}


int main() {
	int N,M;
	cin>>N>>M;
	vector<int> AdjList[10001];
	int indegree[10001] ={0};
	for(int i = 0; i < M; i++){
		int v1,v2;
		cin>>v1>>v2;
		AdjList[v1].push_back(v2);
		indegree[v2] += 1;
	}
	
	printOrder(AdjList, indegree, N);
	
	return 0;
}