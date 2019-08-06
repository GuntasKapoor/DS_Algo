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

	void addedge(T u,T v){
		adjlist[u].push_back(v);
	}

	int BFS(T src,T dest){
		queue<T> q;
		q.push(src);
		map<T,int> dist;
		map<T,T> parent;
		for(auto it = adjlist.begin();it!= adjlist.end();it++){
			dist[it->first]=-1;
		}
		dist[src]=0;
		while(!q.empty()){
			T top = q.front();
			q.pop();
			for(auto it=adjlist[top].begin();it!=adjlist[top].end();it++){
				if(dist[*it]==-1){
					dist[*it]=dist[top]+1;
					q.push(*it);
					parent[*it]=top;
				}
			}
		}
		T temp=dest;
		while(temp!=src){
			cout<<temp<<"-->";
			temp=parent[temp];
		}
		cout<<src;
		return dist[dest];
	}


	void printGraph(){
		for(auto it=adjlist.begin();it!=adjlist.end();it++){
			cout<<it->first<<"-->";
			for(auto i=it->second.begin();i!=it->second.end();i++){
				cout<<*i<<",";
			}
			cout<<endl;
		}
	}

};


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
Graph<int> g(37);
int board[50]={0};

board[2]=13;
board[5]=2;
board[9]=18;
board[18]=11;
board[17]=-13;
board[20]=-14;
board[24]=-8;
board[25]=-10;
board[32]=-2;
board[34]=-22;
for(int u=0;u<=36;u++){
	for(int v=u+1;v<=u+6;v++){
		g.addedge(u,v+board[v]);
	}
}
g.BFS(0,36);
// g.printGraph();
}