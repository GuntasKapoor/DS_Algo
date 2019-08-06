// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int T,N,K;
cin>>T;
while(T--){
	cin>>N>>K;
	int array[100000];
	for(int i=0;i<N;i++){
		cin>>array[i];
	}
	int ans = INT_MIN;
	for(int i=0;i<K;i++){
		int count=0;
		int maxcount=INT_MIN;
		for(int j=i;j<N;j+=K){
			count+=array[j];
			maxcount=max(maxcount,count);
			if(count<0){
				count=0;
			}
		}
		ans=max(ans,maxcount);
	}
	cout<<ans<<endl;
}

}