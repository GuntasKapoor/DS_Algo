#include <bits/stdc++.h>
using namespace std;
int solve(int n,vector<int>A){
  
    int freq[1001] = {0};
    int maxvalue = -1;
    
    for(int i = 0; i < n; i++){
        freq[A[i]]+=1;
        maxvalue = max(maxvalue, A[i]);
    }
    
    int dp[1001];
    dp[0] = 0;
    dp[1] = freq[1];
    dp[2] = max(dp[1], 2*freq[2]);
    
    for(int i = 3; i <= maxvalue, i++){
        if(freq[i] > 0){
    		dp[i] = max(dp[i - 1], dp[i - 2] + freq[i]*i);       
        }
        else{
            dp[i] = dp[i - 1];
        }
    }
return dp[maxvalue + 1];
}