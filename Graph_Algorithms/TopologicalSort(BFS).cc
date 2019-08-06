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
map<T,int> indegree;
public:
	Graph(int Vert){
		V=Vert;
	}
	void add_Edge(T u,T v){
		adjlist[u].push_back(v);
		indegree[v]++;
	}
	void topologicalSorting(){
		// We can also use priority queue if needed..!
		queue<T> q;
		for(auto it=adjlist.begin();it!=adjlist.end();it++){
			if(indegree[it->first]==0){
				q.push(it->first);
			}
		}
		while(!q.empty()){
			T top=q.front();
			q.pop();
			cout<<top<<"->";
			for(auto it=adjlist[top].begin();it!=adjlist[top].end();it++){
				indegree[*it]--;
				if(indegree[*it]==0){
					q.push(*it);
				}
			}
		}

	}
	void printIndegree(){
		for(auto it=indegree.begin();it!=indegree.end();it++){
			cout<<it->second<<" ";
		}
	}
};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
Graph<string> g(9);
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
g.topologicalSorting();
cout<<endl;
// After topological Sorting indegree will be 0 for all nodes...!
g.printIndegree();
}