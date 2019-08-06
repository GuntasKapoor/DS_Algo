// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int LongestAP(vector<int> A){
	int maxele = -1;
    int minele = INT_MAX;
    int N = A.size();
    if(N == 0){
        return 0;
    }
    for(int i = 0; i < N; i++){
        if(A[i] > maxele){
            maxele = A[i];
        }
        if(A[i] < minele){
            minele = A[i];
        }
    }
    int maxdiff = maxele - minele;
    // long long int **dp = new long long int*[N];
    // for(int i = 0; i < N; i++){
    //     dp[i] = new long long int[2*maxdiff + 1];
    //     for(int j = 0; j <= 2*maxdiff; j++){
    //         dp[i][j] = 1;
    //     }
    // }
    unordered_map<int, int> dp;
    for(int i = -maxdiff; i <= maxdiff; i++){
        dp[i] = 1;
    }
    int longest = 1;
    for(int i = N - 2; i >= 0; i--){
        for(int j = i + 1; j < N; j++){
            int diff = A[j] - A[i];
            
                dp[diff] = max(dp[diff], 1 + dp[diff]);
                if(dp[diff] > longest){
                    longest = dp[diff];
            }
            
        }
    }
    return longest;
}









int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N;
cin>>N;
vector<int> A(N);
for(int i = 0; i < N; i++){
	cin>>A[i];
}
cout<<LongestAP(A);
}