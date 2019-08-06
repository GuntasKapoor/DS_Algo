// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


// Question link:- https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/
int recursive_approach(int freq[],int i,int j,int level){
	if(i>j){
		return 0;
	}
    int min_cost=INT_MAX;
	for(int r=i;r<=j;r++){
    int cost=freq[r]*level + recursive_approach(freq,i,r-1,level+1) + recursive_approach(freq,r+1,j,level+1);
    min_cost=min(min_cost,cost);
	}
	return min_cost;
}
int getsum(int freq[],int i,int j){
	int sum=0;
	for(int r=i;r<=j;r++){
		sum+=freq[r];
	}
	return sum;
}

int dpSolution(int freq[],int N){
	int dp[N][N];
	for(int i=0;i<N;i++){
		dp[i][i]=freq[i];
	}
	for(int L=2;L<=N;L++){
		for(int start=0;start<=N-L+1;start++){
			int j=start+L-1;
			dp[start][j]=INT_MAX;
			for(int r=start;r<=j;r++){
				int cost=((r>start)?dp[start][r-1]:0)
							+ ((r<j)?dp[r+1][j]:0)
							+ getsum(freq,start,j);
				dp[start][j]=min(dp[start][j],cost);
			}
		}
	}
	return dp[0][N-1];
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int freq[100];
int N;
cin>>N;
for(int i=0;i<N;i++){
	cin>>freq[i];
}
// cout<<recursive_approach(freq,0,N-1,1);
cout<<dpSolution(freq,N)<<endl;
}