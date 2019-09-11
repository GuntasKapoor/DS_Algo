// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;
#define long long ll


ll helper(int N, string s, int K){

	if(N == 0 && K == 0){
		return 1;
	}
	if(N > 0 && N < 3 && K == 0){
		return pow(26, N);
	}
	if(N < 0){
		return 0;
	}

	ll ans = 0;
	for(int i = 0; i < N; i++){
		
	}
}






int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N,K;
cin>>N>>K;
ll ans = 0;
if(N >= 4){
ll ans = helper(N, "goog");
}
cout<<ans<<endl;
}