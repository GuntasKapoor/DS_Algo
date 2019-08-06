// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

bool compare(pair<int,int> a,pair<int,int> b){
	if(a.first<b.first){
		return true;
	}
	else if(a.first == b.first){
		return a.second<b.second;
	}
	return false;
}

int fencelength(vector<pair<int,int>> v){
	map<pair<int,int>, bool > visited;
	int totalcount = 4;
	visited[make_pair(v.begin()->first,v.begin()->second)] = true;
	for(auto it = v.begin() + 1; it!=v.end();it++){
		int r = it->first;
		int c = it->second;
		totalcount+=4;
		visited[make_pair(r,c)]=true;
		if(r - 1 >= 0){
			if(visited[make_pair(r -1, c)] == true){
				totalcount -= 2;
			}
		}
		if(c-1>=0){
			if(visited[make_pair(r, c - 1)] == true){
				totalcount -= 2;
			}
		}
	}
	return totalcount;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int T; cin>>T;
while(T--){
	int N,M,K;
	cin>>N>>M>>K;
	vector<pair<int,int>> v;
	for (int i=0;i<K;i++){
		int r,c;
		cin>>r>>c;
		v.push_back(make_pair(r,c));
	}
	sort(v.begin(),v.end(),compare);
	cout<<fencelength(v)<<endl;
}

}