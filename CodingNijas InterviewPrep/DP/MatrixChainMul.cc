// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


int MCM(int * arr, int N){

	int ** dp = new int*[N];

	for(int i = 0; i <= N; i++){
		dp[i] = new int[N];
	}
	// Base cases
	for(int i = 0; i < N; i++){
		dp[i][i] = 0;
	}

	for(int i = 0; i < N - 1; i++){
		dp[i][i + 1] = 0;
	}

	for(int k = 2; k < N; k++){
		int i = 0;
		int j = k;

		while(i < N && j < N){
			dp[i][j] = min(dp[i][j - 1] + arr[i]*arr[j - 1]*arr[j], dp[i + 1][j] + arr[i]*arr[i + 1]*arr[j]);
			i++;
			j++;
		}
	}
	return dp[0][N -1];
}





int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N;
cin>>N;
int arr[1000];
for(int i = 0; i < N; i++){
	cin>>arr[i];
}

int minOperations = MCM(arr, N);
cout<<minOperations<<endl;
}
