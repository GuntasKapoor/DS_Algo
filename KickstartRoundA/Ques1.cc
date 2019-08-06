// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int T,N,P;
int S[1000000];
cin>>T;
int c=1;
while(T--){
	cin>>N>>P;
	for(int i=0;i<N;i++){
		cin>>S[i];
	}
	sort(S,S+N);
	int minchange=INT_MAX;
	for(int i=0;i<=N-P;i++){
		int count=0;
		for(int j=i;j<i+P-1;j++){
			count+=(S[i+P-1]-S[j]);
		}
		minchange=min(minchange,count);
	}
	cout<<"Case #"<<c<<": "<<minchange<<endl;
	c++;
}

}