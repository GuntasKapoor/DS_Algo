#include <bits/stdc++.h>
using namespace std;


void EulerTour(vector<int> AdjList[] , vector<int> &eulertour, vector<int> &levels, int firstoccurrence[], int start, int level){
	
	eulertour.push_back(start);
	levels.push_back(level);
	if(firstoccurrence[start] == -1){
		firstoccurrence[start] = eulertour.size() - 1;
	}
	for(int i = 0; i < AdjList[start].size(); i++){
		EulerTour(AdjList, eulertour, levels, firstoccurrence, AdjList[start][i], level + 1);
		eulertour.push_back(start);
		levels.push_back(level);
	}
	return;
}

void buildSegtree(int Segtree[], vector<int> levels, int ss, int se, int si){
	if(ss == se){
		Segtree[si] = ss;
		return;
	}
	
	int mid = (ss + se)/2;
	buildSegtree(Segtree, levels, ss, mid , 2*si + 1);
	buildSegtree(Segtree, levels, mid + 1, se, 2*si + 2);
	if(levels[Segtree[2*si + 1]] > levels[Segtree[2*si + 2]]){
		Segtree[si] = Segtree[2*si + 2];
	}
	else{
		Segtree[si] = Segtree[2*si + 1];
	}
	return;
}

int query(int Segtree[], vector<int> levels, int ss, int se, int si,int qs, int qe){
	// Complete Overlap
	if(qs<=ss && qe>=se){
		return Segtree[si];
	}
	// No Overlap
	if(qs>se || qe<ss){
		return -1;
	}
	// Partial Overlap

	int mid = (ss+se)/2;
	int left = query(Segtree, levels,ss, mid, 2*si + 1, qs, qe);
	int right = query(Segtree, levels,mid + 1, se, 2*si + 2, qs, qe);
	if(left!=-1 && right!=-1){
	if(levels[left] > levels[right]){
		return right;
	}
	else{
		return left;
	}
}
	else if(left!=-1){
		return left;
	}
	return right;

}


int main() {
	int t;
	cin>>t;
	int T = 1;
	while(t--){
		int N;
		cin>>N;
		vector<int> AdjList[1001];
		// Build the tree
		for(int i = 1; i <= N; i++){
			int noChild;
			cin>>noChild;
			for(int j = 0; j < noChild; j++){
				int child;
				cin>>child;
				AdjList[i].push_back(child);
			}
		}
		vector<int> eulertour, levels;
		int firstoccurrence[N + 1];
		fill(firstoccurrence, firstoccurrence + N + 1, -1);
		// Find the Euler tour and Levels of every Eulertour node;
		EulerTour(AdjList, eulertour, levels, firstoccurrence,1, 0);
		int Segtree[10000];
		// Build the segment tree of levels with RMQ
		buildSegtree(Segtree, levels, 0, levels.size() - 1, 0);
		int Q;
		cin>>Q;
		cout<<"Case "<<T<<':'<<endl;
		for(int i = 0; i < Q; i++){
			int u,v;
			cin>>u>>v;
			if(firstoccurrence[u] > firstoccurrence[v]){
				swap(u,v);
			}
			// cout<<u<<" "<<v<<endl;
			int qs = firstoccurrence[u];
			int qe = firstoccurrence[v];
			// cout<<qs<<" "<<qe<<endl;
			int idx = query(Segtree,levels, 0, levels.size() - 1, 0, qs,qe);
			// cout<<idx<<endl;
			cout<<eulertour[idx]<<endl;
		}
	T++;
	}
	return 0;
}