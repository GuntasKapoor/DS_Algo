// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


int CoinChange(int coins[],int N,int M){
	if(N==0){
		return 1;
	}
	if(N<0){
		return 0;
	}
	if(M<0 && N>0){
		return 0;
	}

	return CoinChange(coins,N,M-1) + CoinChange(coins,N-coins[M-1],M);
}


int BottomUpApproach(int coins[],int N,int M){
	int dp[N+1][M]={0};
	for(int i=0;i<M;i++){
		dp[0][i]=1;
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<M;j++){
			if(i>=coins[j]){
				dp[i][j]+=dp[i-coins[j]][j]; //take that coin
			}
			if(j>=1){
				dp[i][j]+=dp[i][j-1]; //Dont take the coin
			}
		}
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<M;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[N][M-1];
}

// Approach 3 with space optimization--> O(1)

int spaceoptimized(int coins[],int N,int M){
	int dp[N+1]={0};
	dp[0]=1;
	for(int i=0;i<M;i++){
		for(int j=coins[i];j<=N;j++){
			dp[j]+=dp[j-coins[i]];
		}
	}
	return dp[N];
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N,M;
cin>>N>>M;
int coins[100];
for(int i=0;i<M;i++){
	cin>>coins[i];
}
// int ans=CoinChange(coins,N,M);
// int ans=BottomUpApproach(coins,N,M);
int ans=spaceoptimized(coins,N,M);
cout<<ans<<endl;
}