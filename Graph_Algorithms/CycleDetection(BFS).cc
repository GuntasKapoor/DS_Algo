// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

// We have to detect if there is a cycle in the graph or not using BFS..!
// The idea is to check if we can reach a node which is already visited and its not the parent..!
template<typename T>
class Graph{
	map<T,list<T>> adjlist;
public:	
	Graph(){

	}
	void addEdge(T u,T v){
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	bool BFS(T src){
		queue<T> q;
		q.push(src);
		map<T,bool> visited;
		map<T,T> parent;
		visited[src]=true;
		parent[src]=src;
		while(!q.empty()){
			T top=q.front();
			q.pop();
			for(auto it=adjlist[top].begin();it!=adjlist[top].end();it++){
				if(visited[*it]==true && *it!=parent[top]){
					cout<<"cycle detected";
					return true;
									}
				if(visited[*it]!=true){
					q.push(*it);
					visited[*it]=true;
					parent[*it]=top;
				}
			}
		}
		return false;
	}


};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
Graph<int> g;
g.addEdge(1,2);
g.addEdge(1,4);
// g.addEdge(4,3);
g.addEdge(2,3);
cout<<g.BFS(1);
}