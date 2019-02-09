// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

// Time Complexity:- O(2^N)
// Problem Link:-https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
int RecursiveApproach(string s1,string s2,int N,int M,int i,int j){
	if(i==N || j==M){
		return 0;
	}
	if(s1[i]==s2[j]){
		return 1 + RecursiveApproach(s1,s2,N,M,i+1,j+1);
	}
	return max(RecursiveApproach(s1,s2,N,M,i+1,j),RecursiveApproach(s1,s2,N,M,i,j+1));
}
// Time Complexity:- O(N^2)
int dp[100][100];
int DpSolution(string s1,string s2,int N,int M){
	for(int i=0;i<=N;i++){
		for(int j=0;j<=M;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			}
			else if(s1[i-1]==s2[j-1]){
				dp[i][j]=1 + dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
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
int ans=RecursiveApproach(s1,s2,s1.length(),s2.length(),0,0);
int N=s1.length();
int M=s2.length();
int ans2=DpSolution(s1,s2,N,M);
// Printing the Dp table
 // for(int i=0;i<=N;i++){
 // 	for(int j=0;j<=M;j++){
 // 		cout<<dp[i][j]<<" ";
 // 	}
 // 	cout<<endl;
 // }
// cout<<ans<<endl;
 cout<<ans2;
}