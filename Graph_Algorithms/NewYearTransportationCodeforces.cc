// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

class Graph{
map<pair<int,int> ,list<pair<int,int>>> adjlist;
public:
	Graph(){

	}
	void addEdge(int a,int b,int idx1,int idx2){
		adjlist[make_pair(a,idx1)].push_back(make_pair(b,idx2));
	}
	map<pair<int,int>,bool> visited;

	void BFS(pair<int,int> source,int idx){
		queue<pair<int,int>> q;
		q.push(source);
		visited[source]=true;
		bool flag;
		while(!q.empty()){
			pair<int,int> tp=q.front();
			q.pop();
			flag=false;
			for(auto it=adjlist[tp].begin();it!=adjlist[tp].end();it++){
				if(!visited[*it]){
					visited[*it]=true;
					q.push(*it);
					if(*it.second==idx){
						flag=true;
						break;
					}
				}
			}
			if(flag){
				cout<<"YES"<<endl;
				break;
			}
		}
		if(!flag){
			cout<<"NO"<<endl;
		}
	}

}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);




}