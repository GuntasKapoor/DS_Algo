// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int cnt=0;
int memo[100][100];
int EditDistanceRecursive(string s1,string s2,int N,int M,int i,int j){
	cnt++;
	if(s1[i]=='\0' && s2[j]=='\0'){
		return 0;
	}
	if(s1[i]=='\0'){
		return M-j;
	}
	if(s2[j]=='\0'){
		return N-i;
	}
	if(memo[i][j]!=-1){
		return memo[i][j]; 
	}
	if(s1[i]==s2[j]){
		return EditDistanceRecursive(s1,s2,N,M,i+1,j+1); 
	}
	else{
		int q1 = 1 + EditDistanceRecursive(s1,s2,N,M,i+1,j+1);  //replace
		int q2 = 1 + EditDistanceRecursive(s1,s2,N,M,i,j+1);	//insert
		int q3 = 1 + EditDistanceRecursive(s1,s2,N,M,i+1,j);	//delete
		return memo[i][j]=min(q1,min(q2,q3)); //Memoizing
	}
}

int bottom_up(string s1,string s2,int N,int M){
	int dp[N+1][M+1];
	dp[0][0]=0;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=M;j++){
			if(i==0 && j==0){
				dp[i][j]=0;
			}
			else if(i==0){
				dp[i][j]=j;
			}
			else if(j==0){
				dp[i][j]=i;
			}
			else if(s1[i]==s2[j]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				dp[i][j]=1 + min(dp[i-1][j],//delete
								min(dp[i][j-1] // insert 
								,dp[i-1][j-1] //replace
									));
			}
		}
	}
	return dp[N][M];
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s1,s2;
cin>>s1>>s2;
memset(memo,-1,sizeof(memo));
// cout<<EditDistanceRecursive(s1,s2,s1.length(),s2.length(),0,0)<<endl;
// cout<<cnt;
cout<<bottom_up(s1,s2,s1.length(),s2.length())<<endl;
}