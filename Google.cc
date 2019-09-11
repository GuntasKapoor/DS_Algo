// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;



int helper(string s){
unordered_map<string, bool> instructions;
instructions["L"] = true;
instructions["R"] = true;
instructions["D"] = true;
instructions["U"] = true;
instructions["DL"] = true;
instructions["LD"] = true;
instructions["RD"] = true;
instructions["DR"] = true;
instructions["LU"] = true;
instructions["UL"] = true;
instructions["RU"] = true;
instructions["UR"] = true;

	int *dp = new int[s.length() + 1];
	fill(dp, dp + s.length() + 1, 0);
	string a;
	dp[0] = 1;
	
	a = s.substr(0, 2);
	dp[1] = dp[0];
	if(instructions[a]){
		dp[1] += 1;
	}

	for(int i = 2; i < s.length(); i++){
		dp[i] += dp[i - 1];
		a = s.substr(i - 1, 2);
		if(instructions[a]){
			dp[i] += dp[i - 2];	
		}
	}
	int ans = dp[s.length() - 1];
	delete []dp;
	return ans;
}







int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);



string ins;
cin>>ins;
int ans = helper(ins);
cout<<ans<<endl;

}