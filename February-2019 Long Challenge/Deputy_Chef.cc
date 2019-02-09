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
	int N;
	cin>>N;
	int defense[10000];
	int attack[10000];
	for(int i=0;i<N;i++){
		cin>>attack[i];
	}
	for(int i=0;i<N;i++){
		cin>>defense[i];
	}
	int prev,next;
	int maxi=-1;
	for(int i=0;i<N;i++){
		if(i==0){
			prev=N-1;
			next=i+1;
		}
		else if(i==N-1){
			prev=i-1;
			next=0;
		}
		else{
			prev=i-1;
			next=i+1;
		}
		if(defense[i]>(attack[prev]+attack[next])){
			maxi=max(maxi,defense[i]);
		}
	}
	cout<<maxi<<endl;
}
}