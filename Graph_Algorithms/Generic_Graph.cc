// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

template<typename T>
class Graph{
	int V;
	map<T,list<T>> mp;
public:
	Graph(int vert){
		V=vert;
	}
	void addEdge(T a,T b,bool bidir=true){
		mp[a].push_back(b);
		if(bidir){
			mp[b].push_back(a);
		}
	}
	void print(){
		for(auto it=mp.begin();it!=mp.end();it++){
			cout<<it->first<<" --> ";
			for(auto i=(it->second).begin();i!=(it->second).end();i++){
				cout<<*i<<" ";
			}
			cout<<endl;
		}
	}
};


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Graph<string> g(7);

g.addEdge("Moga","Ludhiana");
g.addEdge("Patiala","Chandigarh");
g.addEdge("Jalandhar","Amritsar");
g.addEdge("Moga","Nawanshahr");
g.print();
}