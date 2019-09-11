#include <bits/stdc++.h>
using namespace std;

bool func(vector<pair<int,int>> AdjList[], int N){
	int val[101];
	fill(val, val + N, -1);
	val[1] = 1;
	queue<pair<int,int>> q;
	q.push(make_pair(1,1));

	while(!q.empty()){
		pair<int, int> front = q.front();
		q.pop();
		int node = front.first;
		int v = front.second;
		for(int i = 0; i < AdjList[node].size(); i++){
			int n = (AdjList[node][i]).first;
			if(val[n] == -1){
				if(v == 0){
					val[n] = 1 - AdjList[node][i].second;
				}
				else{
					val[n] = AdjList[node][i].second;
				}
				q.push(make_pair(n, val[n]));
			}
			else{
				if(v == 0){
					if((1 - AdjList[node][i].second) != val[n]){
						
						return true;
					}
				}
				else{
					if(AdjList[node][i].second != val[n]){
						return true;
					}
				}
			}
		}	
	}
	return false;
}


int main() {
	
	int N;
	while(true){
		cin>>N;
		if(N == 0){
			break;
		}
		vector<pair<int,int>> AdjList[101];
		for(int i = 1; i <= N; i++){
			int v;
			string val;
			cin>>v>>val;
			int ival;
			if(val == "false"){
				ival = 0;
			}
			else{
				ival = 1;
			}
			AdjList[i].push_back(make_pair(v, ival));
		}
	 	bool check = func(AdjList, N);
		if(check){
			cout<<"PARADOX"<<endl;
		}
		else{
			cout<<"NOT PARADOX"<<endl;
		}
	}
	
	return 0;
}