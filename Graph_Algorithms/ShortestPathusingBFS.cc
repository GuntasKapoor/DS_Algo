// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

template<typename T>
class Graph{
	int vertices;
	map<T,list<T>> mp;
public:
	Graph(int V){
		vertices=V;
	} 
	void addEdge(T u,T v){
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	void shortestPath(T source){
		queue<T> q;
		q.push(source);
		map<T,int> dist;
		for(auto i=mp.begin();i!=mp.end();i++){
			dist[i->first]=-1;
		}
		dist[source]=0;
		while(q.empty()!=true){
			T tp=q.front();
			q.pop();
			for(auto it=mp[tp].begin();it!=mp[tp].end();it++){
				if(dist[*it]==-1){
					dist[*it]=dist[tp]+1;
					q.push(*it);
				}
			}
	    }
	    for(auto it=dist.begin();it!=dist.end();it++){
	    	if((it->first)!=source)
	    	cout<<"distance of "<<it->first<<" from "<<source<<" is "<<it->second<<endl;
	    }
	}
};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Graph<char> g(5);
g.addEdge('a','b');
g.addEdge('a','e');
g.addEdge('b','c');
g.addEdge('c','e');
g.addEdge('c','d');
g.addEdge('d','f');
g.shortestPath('a');
}