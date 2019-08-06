// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

template<typename T>
class Graph{

map<T,list<T>> adjlist;
public:
	Graph(){
	}
	void add_Edge(T u,T v){
		adjlist[u].push_back(v);
	}
	map<T,bool> visited,instack;
	bool detectCycle(T src){
		visited[src]=true;
		instack[src]=true;
		for(auto it=adjlist[src].begin();it!=adjlist[src].end();it++){
			if(instack[*it]==true){
				return true;
			}
			else if(!visited[*it] && detectCycle(*it)){
				return true;
			}
		}
		instack[src]=false;
		return false;
	}


};


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
Graph<int> g;
g.add_Edge(0,2);
g.add_Edge(0,1);
g.add_Edge(2,3);
// g.add_Edge(3,0);
g.add_Edge(2,4);
g.add_Edge(4,5);
g.add_Edge(1,5);
cout<<g.detectCycle(0);
}