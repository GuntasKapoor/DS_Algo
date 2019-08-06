// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int maxlen = 0;
void SuperBalanced(string s, int length, int open , int close , int idx){

	if(idx == s.length()){
		if(open == close){
			maxlen = max(maxlen, length);
		}
		return;
	}


	if(s[idx] == '('){
		if(close == 0){
			// If any closed bracket hasn't came yet then take the opening
			SuperBalanced(s,length + 1, open + 1, close, idx + 1);
		}
	}
	else{
		if(close < open){
			SuperBalanced(s, length + 1, open, close + 1, idx + 1);
		}
	}
	SuperBalanced(s, length, open, close, idx + 1);
	return;
}



int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

string s;
cin>>s;
// int dp[100001];
// for(int i = 0; i < s.length() + 1; i++){
// 	dp[i] = -1;
// }
SuperBalanced(s, 0, 0, 0, 0);
cout<<maxlen<<endl;
}