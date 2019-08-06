// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

template<typename T>
class Graph
{
	map<T,list<pair<T,int>>> adjlist;
public:
	Graph(){}
	
	void addEdge(T u,T v,int dist,bool bidir=false){
		// if the Graph is Undirected you have to also maintain a visited map/array.
		// Here the Graph is Directed or Unidirectional...!
		adjlist[u].push_back(make_pair(v,dist));
		if(bidir){
		adjlist[v].push_back(make_pair(u,dist));
		}
	}	

	void printGraph(){
		for(auto it=adjlist.begin();it!=adjlist.end();it++){
			cout<<it->first<<"-->";
			for(auto i=it->second.begin();i!=it->second.end();i++){
				cout<<'('<<i->first<<","<<i->second<<')';
							}
							cout<<endl;
		}
	}

	void Dijkstra(T src){
		map<T,int> dist;
		for(auto it=adjlist.begin();it!=adjlist.end();it++){
			dist[it->first]=INT_MAX;
		}
		dist[src]=0;
		// A set is used to store the distances of the nodes. A set sorts the values in increasing order;
		set<pair<int,T>> s;
		s.insert(make_pair(0,src));
		while(!s.empty()){
			pair<int,T> p = *s.begin();
			s.erase(s.begin());
			for(auto it=adjlist[p.second].begin();it!=adjlist[p.second].end();it++){
				if(dist[p.second] + it->second<dist[it->first]){
					auto i = s.find(make_pair(dist[it->first],it->first));
					if(i!=s.end()){
						s.erase(i);
					}
					dist[it->first]=dist[p.second] + it->second;
					s.insert(make_pair(dist[it->first],it->first));
				}
			}
		}
		for(auto it=adjlist.begin();it!=adjlist.end();it++){
			cout<<"Distance of"<<it->first<<"-->"<<dist[it->first]<<endl;
		}
	}
	
};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Graph<int> g;
g.addEdge(0,1,1);
g.addEdge(0,2,4);
g.addEdge(0,3,7,true);
g.addEdge(1,2,1);
g.addEdge(2,3,2);
g.printGraph();
g.Dijkstra(0);
}