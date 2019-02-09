// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int multiply(int i,int j,int array[]){
	int result=1;
	for(int k=i;k<=j;k++){
		result*=array[k];
	}
	return result;
}
// Time Complexity:- O(2^N);
int memo[501][501];
int RecursiveApproach(int indicesMatrix[],int i,int j,int N){
	if(N==3){
		int mul=multiply(i,j,indicesMatrix);
		return mul;
	}
	if(memo[i][j]!=-1) return memo[i][j];
	int q1=RecursiveApproach(indicesMatrix,i+1,j,N-1);
	int q2=RecursiveApproach(indicesMatrix,i,j-1,N-1);
	memo[i][j]=min(q1 + indicesMatrix[i]*indicesMatrix[i+1]*indicesMatrix[j],q2 + indicesMatrix[i]*indicesMatrix[j-1]*indicesMatrix[j]);
	return memo[i][j];
}

// Time Complexity:- O(N^2) (Huge Improvement Yaay..!)

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N,T;
cin>>T;
while(T--){
cin>>N;
memset(memo,-1,sizeof(memo));
int array[100];
for(int i=0;i<N;i++){
	cin>>array[i];
}
int ans=RecursiveApproach(array,0,N-1,N);
cout<<ans<<endl;
}
}