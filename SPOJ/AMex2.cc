#include <bits/stdc++.h>

int solution(string &S) {
    int n = S.length();
    if(n <= 2){
        return n;
    }
    int dp[200001];
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i < n; i++){
        if(S[i] == S[i - 1] && S[i] == S[i - 2]){
            dp[i] = 2;   
        }
        else{
            dp[i] = dp[i - 1] + 1;   
        }
    }
    int maxlen = 0;
    for(int i = 0; i < n; i++){
        maxlen = max(maxlen, dp[i]);
    }
    return maxlen;
}
