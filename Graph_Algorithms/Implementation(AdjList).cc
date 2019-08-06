// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

template <typename T>
class Graph{
int Vertices;
list<T> *l;

public:
	Graph(int V){
		Vertices=V;
		l=new list<T>[V];
	}
	void addEdge(T a,T b,bool bidir=true){
		l[a].push_back(b);
		if(bidir){
			l[b].push_back(a);
		}
	}	

	void printGraph(){
		for(int i=0;i<Vertices;i++){
			for(auto it=l[i].begin();it!=l[i].end();it++){
				cout<<*it<<" ";
			}
			cout<<endl;
		}
	}

};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Graph<int> g(7);

g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(4,5,false);
g.printGraph();

}