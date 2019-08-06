// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;










int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N, M;
cin>>N>>M;
string input[1001];
for(int i = 0; i < N; i++){
	cin>>input[i];
}
int values[1001];
int ans = 0;
for(int i = 0; i < M; i++){
	cin>>values[i];
}

for(int i = 0; i < M; i++){
	int dp[5]={0};
	for(int j = 0; j < N; j++){
		char c = input[j][i];
		dp[c - 'A'] += 1; 
	}
	int maxi = 0;
	for(int j = 0; j < 5; j++){
		maxi = max(maxi, dp[j]);
	}
 ans+= (maxi*values[i]);
}
cout<<ans<<endl;
}
