// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
template<typename T>
class Graph{

int Vertices;
map<T,list<T>> mp;
public:
	Graph(int V){
		Vertices=V;
	}

	void addEdge(T a,T b){
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	void printgraph(){
		for(int i=0;i<Vertices;i++){
			cout<<i<<"-->";
		for(auto it=mp[i].begin();it!=mp[i].end();it++){
			cout<<*it<<",";
		}
		cout<<endl;
	}
	}
	void BFS(T start){
		map<T,bool> visited;
		queue<T> q;
		q.push(start);
		visited[start]=true;
		while(q.empty()!=true){
			T a=q.front();
			q.pop();
			cout<<a<<" ";
			for(auto it = mp[a].begin();it != mp[a].end();it++){
				if(visited[*it]!=true){
				q.push(*it);
				visited[*it]=true;
			}
			}
		}
	}
};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Graph<int> g(5);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(0,3);
g.addEdge(1,2);
g.addEdge(2,4);
g.addEdge(3,4);
g.printgraph();
g.BFS(0);
}