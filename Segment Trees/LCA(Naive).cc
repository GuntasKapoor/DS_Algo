#include <bits/stdc++.h>
using namespace std;

bool traversal1(vector<int> AdjList[],int visited[], int start,int a){
	
	if(start == a){
		visited[a] = 1;
		return true;
	}
	
	for(int i = 0; i < AdjList[start].size(); i++){
		bool ans = traversal1(AdjList, visited, AdjList[start][i], a);
		if(ans){
			visited[start] = 1;
			return true;
		}
	}
	return false;
}

int LCA(vector<int> AdjList[],int visited[], int start, int b){
	if(start == b){
		if(visited[b] == 1){
			return b;
		}
		return 0;
	}
	
	for(int i = 0; i < AdjList[start].size(); i++){
		int ans = LCA(AdjList, visited, AdjList[start][i], b);
		if(ans == 0){
			if(visited[start]){
				return start;
			}
			return 0;
		}
		if(ans > 0){
			return ans;
		}
	}
	return -1;
}

int main() {
	// Naive Solutions(With space complexity as n);
	
	int t;
	cin>>t;
	int T = 1;
	while(t--){
		int N;
		cin>>N;
		vector<int> AdjList[1001];
		for(int i = 1; i <= N; i++){
			int noChild;
			cin>>noChild;
			for(int j = 0; j < noChild; j++){
				int child;
				cin>>child;
				AdjList[i].push_back(child);
			}
		}
		int Q;
		cin>>Q;
		cout<<"Case "<<T<<':'<<endl;
		for(int i = 0; i < Q; i++){
			int a,b;
			cin>>a>>b;
			int visited[1001]={0};
			bool t1 = traversal1(AdjList, visited, 1,a);
			if(t1){
			int ans = LCA(AdjList, visited, 1, b);
			cout<<ans<<endl;
			}
	}
	T++;
	}
	return 0;
}