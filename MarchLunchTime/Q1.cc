// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T;
cin>>T;
while(T--){
	int N,X;
	cin>>N>>X;
	string str;
	cin>>str;
	map<int,bool> visited;
	visited[X]=true;
	int count=1;
	for(int i=0;i<N;i++){
		if(str[i]=='R'){
			X=X+1;
			if(visited[X]!=true){
				count+=1;
				visited[X]=true;
			}
		}
		else if(str[i]=='L'){
			X-=1;
			if(visited[X]!=true){
				count+=1;
				visited[X]=true;
			}
		}
	}
	cout<<count<<endl;
}

}