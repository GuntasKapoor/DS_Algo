// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

template<typename T>
class Graph{

int V;
map<T,list<T>> adjlist;

public:
	Graph(int v){
		V=v;
	}
	void addEdge(T u,T v){
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}	
	map<T,bool> visited;
	void DFShelper(T src){
		visited[src]=true;
		cout<<src<<"-->";
		for(auto it = adjlist[src].begin();it!=adjlist[src].end();it++){
			if(!visited[*it]){
				DFShelper(*it);
			}
		}
		return;
	}
	void DFS(T src){
	int components=1;
		DFShelper(src);
		for(auto it=adjlist.begin();it!=adjlist.end();it++){
			if(!visited[it->first]){
				cout<<endl;
				DFShelper(it->first);
				components++;
			}
		}
		cout<<"Total No of Components "<<components;
	}

};



int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
Graph<char> g(6);
g.addEdge('a','b');
g.addEdge('a','e');
g.addEdge('b','c');
g.addEdge('c','e');
g.addEdge('c','d');
g.addEdge('d','f');
g.addEdge('i','j');
g.DFS('a');
}