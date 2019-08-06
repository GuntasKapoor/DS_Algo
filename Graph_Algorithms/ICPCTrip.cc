// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

class Fare{

public:
	int flight,train;
	Fare(int t,int f){
		flight=f;
		train=t;
	}

};
template<typename T>
class Graph{
map<T,list<pair<T,Fare>>> adjlist;
public:
	Graph(){
	}
	void add_Edge(T u,T v,int train,int flight){
		Fare f(train,flight);
		adjlist[u].push_back(make_pair(v,f));
		adjlist[v].push_back(make_pair(u,f));
	}

	map<T,int> Dijkstra(T src)
	{
		map<T,int> dist;
		set<pair<int,T>> s;
		for(auto it=adjlist.begin();it!=adjlist.end();it++){
			dist[it->first]=INT_MAX;
		}
		dist[src]=0;
		s.insert(make_pair(0,src));
		while(!s.empty()){
			pair<int,T> p = *s.begin();
			s.erase(s.begin());
			for(auto it=adjlist[p.second].begin();it!=adjlist[p.second].end();it++){				
				if(p.first + it->second.train < dist[it->first]){
					auto f=s.find(make_pair(dist[it->first],it->first));
					if(f!=s.end()){
						s.erase(f);
					}
					dist[it->first]=p.first + it->second.train;
					s.insert(make_pair(dist[it->first],it->first));
				}

			}
		}
		return dist;
	}	

	int IcpcTrip(T src,T dest){
		std::map<T, int> dist1=Dijkstra(src);
		std::map<T, int> dist2=Dijkstra(dest);
		int shortestDist=INT_MAX;
		for(auto it=adjlist.begin();it!=adjlist.end();it++){
			for(auto ot=adjlist[it->first].begin();ot!=adjlist[it->first].end();ot++){
				shortestDist=min(shortestDist,dist1[it->first]+dist2[ot->first]+ot->second.flight);
			}
			shortestDist=min(shortestDist,dist1[dest]);
		}
		return shortestDist;
	}

};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Graph<string> g;

g.add_Edge("ASR","JAIPUR",5,4);
g.add_Edge("ASR","Delhi",3,8);
g.add_Edge("Delhi","JAIPUR",2,6);
g.add_Edge("JAIPUR","PUNE",6,2);
g.add_Edge("Delhi","Bhopal",7,14);
g.add_Edge("Bhopal","Amritapuri",1,2);
g.add_Edge("Bhopal","Mumbai",6,3);
g.add_Edge("Mumbai","Amritapuri",8,9);
g.add_Edge("PUNE","Goa",11,6);
g.add_Edge("PUNE","Amritapuri",3,10);
g.add_Edge("Goa","Amritapuri",13,12);
cout<<g.IcpcTrip("ASR","Amritapuri");

}