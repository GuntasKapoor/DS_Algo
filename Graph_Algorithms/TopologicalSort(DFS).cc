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
		Graph(int Vertices){
			V=Vertices;
		}
	void add_Edge(T u,T v){
		adjlist[u].push_back(v);
	}	
	map<T,bool> visited;
	list<T> topological_order;
	void DFShelper(T src){
		visited[src]=true;
		for(auto it=adjlist[src].begin();it!=adjlist[src].end();it++){
			if(!visited[*it]){
				DFShelper(*it);
			}
		}
		// Push the node that has visited all its children to the front;
		topological_order.push_front(src);
		return;
	}
	void DFS(T src){
		DFShelper(src);
		// TO check if any Node is left or not(in the example in main Maths will be left);
		for(auto it=adjlist.begin();it!=adjlist.end();it++){
			if(!visited[it->first]){
				cout<<endl;
				DFShelper(it->first);
			}
		}
		for(typename list<T>::iterator it=topological_order.begin();it!=topological_order.end();it++){
			cout<<*it<<" ";
		}
	}
};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
Graph<string> g(6);
g.add_Edge("English","Programming Logic");
g.add_Edge("Maths","Programming Logic");
g.add_Edge("Programming Logic","HTML");
g.add_Edge("English","HTML");
g.add_Edge("Programming Logic","Python");
g.add_Edge("Programming Logic","Java");
g.add_Edge("HTML","CSS");
g.add_Edge("CSS","JS");
g.add_Edge("Programming Logic","JS");
g.add_Edge("Python","Web Dev");
g.add_Edge("JS","Web Dev");
g.add_Edge("Java","Web Dev");
g.DFS("English");
}