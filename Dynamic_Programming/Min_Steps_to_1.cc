// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


// Question:- Given a No N and 3 operations can be performed on N:-
// 1. we can divide N by 3.
// 2. we can divide N by 2.
// 3. we can subtract 1.
// We have to find min no of operations required to reduce the number to 1.

// Time Complexity of this program is O(3^N) because at every stage of recursion tree there can be 3 nodes
int RecursiveApproach(int N){
	if(N==1){
		return 0;
	}
	int q1=INT_MAX,q2=INT_MAX,q3;
	if(N%3==0){
		q1=1 + RecursiveApproach(N/3);
	}
	if(N%2==0){
		q2=1 + RecursiveApproach(N/2);
	}
	q3=1 + RecursiveApproach(N-1);
	return min(q1,min(q2,q3));
}

int memopad[100000];
int MemoizedSolution(int N){
	if(N==1){
		return 0;
	}
	int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
	if(memopad[N]!=-1){
		return memopad[N];
	}
	if(N%3==0){
		q1=1 + MemoizedSolution(N/3);
	}
	if(N%2==0){
		q2=1 + MemoizedSolution(N/2);
	}
	q3=1 + MemoizedSolution(N-1);
	memopad[N]=min(q1,min(q2,q3));
	return memopad[N];
}

int bottomUp(int N){
	int dp[10000];
	dp[0]=dp[1]=0;
	for(int i=2;i<=N;i++){
		int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
		if(i%3==0){
			q1=1+dp[i/3];
		}
		if(i%2==0){
			q2=1+dp[i/2];
		}
		q3=1+dp[i-1];
		dp[i]=min(q1,min(q2,q3));
	}
	return dp[N];
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N;
cin>>N;
// int recursive_ans=RecursiveApproach(N);
// cout<<recursive_ans<<endl;
fill(memopad,memopad+N+1,-1);
int memoizedsolution=MemoizedSolution(N);
cout<<memoizedsolution<<endl;

int bottomup=bottomUp(N);
cout<<bottomup<<endl;
}