// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


bool compare(pair<string,int> A,pair<string,int> B){
	if(A.second>B.second){
		return true;
	}
	else if(A.second==B.second){
		return A.first<B.first;
	}
	return false;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

vector<pair<string,int>> v;
string s;
int temp;
int x;
cin>>x;
int N;
cin>>N;
for(int i=0;i<N;i++){
	cin>>s>>temp;
	if(temp>=x){
		v.push_back(make_pair(s,temp));
	}
}
sort(v.begin(),v.end(),compare);
for(int i=0;i<v.size();i++){
	cout<<v[i].first<<" "<<v[i].second<<endl;
}
}