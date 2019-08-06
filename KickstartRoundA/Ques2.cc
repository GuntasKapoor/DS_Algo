// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int T,R,C;
cin>>T;
int cas=0;
while(T--){
	cin>>R>>C;
	vector<pair<int,int>> zeros,ones;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			int a;
			cin>>a;
			if(a==0){
				zeros.push_back(make_pair(i,j));
			}
			if(a==1){
				ones.push_back(make_pair(i,j));
			}
		}
	}
	int currentDelTime=0;
	vector<int> store(zeros.size());
	for(int i=0;i<zeros.size();i++){
		store[i]=INT_MAX;
		int c=zeros[i].first;
		int d=zeros[i].second;
		for(int j=0;j<ones.size();j++){
			int a=ones[j].first;
			int b=ones[j].second;
			store[i]=min(store[i],abs(a-c) + abs(b-d));
		}
	}
	for(int i=0;i<store.size();i++){
		currentDelTime=max(currentDelTime,store[i]);
	}
	cout<<currentDelTime<<endl;
	int updatedDelTime=INT_MAX;
	vector <int> minvalues(zeros.size(),INT_MAX);
	for(int i=0;i<zeros.size();i++){
		int c=zeros[i].first;
		int d=zeros[i].second;
		vector<int> store1;
		store1=store;
		for(int j=0;j<zeros.size() && j!=i;j++){
			int a=zeros[j].first;
			int b=zeros[j].second;
			store1[i]=min(store1[i],abs(a-c) + abs(b-d)); 
		}
		int maxi=INT_MIN;
		for(int j=0;j<store1.size();j++){
			maxi=max(maxi,store1[j]);
		}
		minvalues[i]=maxi;
}
for(int i=0;i<minvalues.size();i++){
		updatedDelTime=min(updatedDelTime,minvalues[i]);
	}
	cout<<updatedDelTime;
}
}