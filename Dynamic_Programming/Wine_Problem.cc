// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
int memo[100][100];
int cnt=0;
int Wine_Problem(int wine[],int year,int i,int j){
	if(i>j){
		return 0;
	}
	if(memo[i][j]!=-1){
		return memo[i][j];
	} 
	return memo[i][j]=max(wine[i]*year + Wine_Problem(wine,year+1,i+1,j),wine[j]*year + Wine_Problem(wine,year+1,i,j-1));
}

int bottomUpApproach(int wine[],int N){
	int dp[N][N];
	int year=N;
	for(int i=0;i<N;i++){
		dp[i][i]=year*wine[i];
	}
	year--;
	// Interpret this approach in linear form than in table form...Slide the window on the wine array and not on dp table..!
	// Sliding window..!
	for(int len=2;len<=N;len++){
		int start=0;
		int end=N-len;
		while(start<=end){
			int endofWindow=start+len-1;
			dp[start][endofWindow]=max(wine[start]*year + dp[start+1][endofWindow],wine[endofWindow]*year + dp[start][endofWindow-1]);
			start++;
		}
		year--;
	}
	return dp[0][N-1];
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N;
cin>>N;
int wineprices[100];
for(int i=0;i<N;i++){
	cin>>wineprices[i];
}
memset(memo,-1,sizeof(memo));
// cout<<Wine_Problem(wineprices,1,0,N-1)<<endl;
cout<<bottomUpApproach(wineprices,N)<<endl;
}