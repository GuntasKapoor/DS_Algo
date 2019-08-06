// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

template<typename T>
class Graph{
list<tuple<T,T,int>> edgeList;
int V;
public:
	Graph(int vert){
		V=vert;
	}
	void add_Edge(T u, T v, int dist){
		edgeList.push_back(make_tuple(u,v,dist));
	}
	void BellmanFord(T source){
		map<T,int> dist;
		for(int i=0;i<V;i++){
			dist[i]=INT_MAX;
		}
		dist[source]=0;
		for(int i=0;i<V-1;i++){
			for (auto j=edgeList.begin();j!=edgeList.end();j++){
				T a,b;
				int c;
				tie(a,b,c)=*j;
				if(a!=INT_MAX && dist[a]+c<dist[b]){
					dist[b]=dist[a] + c;
				}
			}
		}
		for (auto j=edgeList.begin();j!=edgeList.end();j++){
				T a,b;
				int c;
				tie(a,b,c)=*j;
				if(a!=INT_MAX && dist[a]+c<dist[b]){
					cout<<"There is a negative weight cycle ";
					break;
				}
	}
	for(int i=0;i<V;i++){
		cout<<"Distance of "<<i<<"from source is "<<dist[i]<<endl;
	}

}
};


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Graph<int> g(5);
g.add_Edge(0,1,-1);
g.add_Edge(0,2,4);
g.add_Edge(1,2,3);
g.add_Edge(1,3,2);
g.add_Edge(3,1,1);
g.add_Edge(1,4,2);
g.add_Edge(4,3,-3);
g.add_Edge(3,2,5);
g.BellmanFord(0);


}