// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

//Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
//In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
//Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
//You cannot break an item, either pick the complete item, or don’t pick it (0-1 property)

// Greedy approach wouldnt work here because there can be a case where picking 2 items of less profit/weight
// ratio gives more profit than 1 item of more ratio..!
// Greedy approach works for Fractional Knapsack..!

// Recursive Solution..!
// Time Complexity= O(2^N) which is Huge.!
int knapsack(int Weight[],int Values[],int N,int capacity){

if(capacity<=0 || N==0){
	return 0;
}
// We have 2 options here:-
// if the capacity is more than the current weight or not..!
if(capacity>=Weight[N-1]){
	// Here we also 2 options..if the capacity is greater than the current weight we can either take it 
	// or leave it to get the maximum profit..!
	return max(knapsack(Weight,Values,N-1,capacity-Weight[N-1])+Values[N-1],knapsack(Weight,Values,N-1,capacity));
}
else{
	return knapsack(Weight,Values,N-1,capacity);
}
}

// Time Complexity--> O(NW)
// DP solution bottom up.
int knapsack_DP(int Weight[],int Values[],int N,int capacity){
int dp[100][100]={0};

for(int i=1;i<=N;i++){
	for(int w=1;w<=capacity;w++){
		if(w>=Weight[i-1]){
			dp[i][w]=max(dp[i-1][w],dp[i-1][w-Weight[i-1]] + Values[i-1]);
		}
		else{
			dp[i][w]=dp[i-1][w];
		}
	}
}
// Printing the dp table
for(int i=0;i<=N;i++){
	for(int w=0;w<=capacity;w++){
		cout<<dp[i][w]<<" ";
	}
	cout<<endl;
}
return dp[N][capacity];
}

int main(){
ios_base::sync_with_stdio(false); //Fast input output
cin.tie(NULL);
int T;
cin>>T;
while(T--){
	int N,W;
	cin>>N>>W;
	int Wt[100],Val[100];
	for(int i=0;i<N;i++){
		cin>>Val[i];
	}
	for(int i=0;i<N;i++){
		cin>>Wt[i];
	}
	int ans=knapsack(Wt,Val,N,W);
	int ans2=knapsack_DP(Wt,Val,N,W);
	cout<<"(Recursive solution)Maximum profit is "<<ans<<endl;	
	cout<<"(DP solution)Max profit is "<<ans2<<endl;
}

}