#include<bits/stdc++.h>
using namespace std;
int summation(vector<int> arr, int s, int e){
    int summ = 0;
    for(int i = s; i <= e; i++){
        summ+=arr[i];
    }
    return summ;
}

int solve(int n,vector<int>colors)
{
    int dp[101][101] = {{0}};
    
    for(int i = 0; i < n; i++){
       	dp[i][i] = 0;
    }
    for(int L = 2; L <= n; L++){
        int i;
		for(i = 1; i <= n - L; i++){
            int start = i;
        	int end = i + L - 1;
        	dp[start][end] = INT_MAX;
        for(int k = start; k < end; k++){
			dp[start][end] = min(dp[start][end], dp[start][k] + dp[k + 1][end]  + summation(colors,start - 1, k - 1)*summation(colors,k, end - 1));
        }
    }
    return dp[0][n];
}