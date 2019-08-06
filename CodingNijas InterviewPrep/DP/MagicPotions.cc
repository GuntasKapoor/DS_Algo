#include<bits/stdc++.h>
#include<vector>
using namespace std;
int helper(int s, int e, vector<int> colors){
    if(s == e){
        return 0;
    }
    int minsmoke = INT_MAX;
    for(int i = s; i < e; i++){
        int smoke = colors[i]*colors[i + 1];
        int leftans = 0;
        
        if(i > s){
        leftans = helper(s, i - 1, colors)
        }
        int rightans = 0;
        if(i < e - 1){
        rightans = helper(i + 2, e, colors);
        }
        minsmoke = min(minsmoke, smoke + leftans + rightans);
    }
    return minsmoke;
}

int solve(int n,vector<int> colors)
{
	int ans = helper(0, n - 1, colors);
    return ans;
}

int main(){

}