// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int countnumbers(int input[],int fact[],int freq[],int n){
	if(n==0 || n==1){
		return 0;
	}

	int ans = 0;
	for(int i = input[0] + 1; i < 10; i++){
		if(freq[i]>0){
			ans += (fact[n-1]*fact[freq[input[0]]])/fact[freq[i]];
		}
	}
	freq[input[0]]--;
	ans+=countnumbers(input + 1, fact, freq, n-1);
	return ans;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int freq[10]={};
int input[10];
int n;
cin>>n;
for(int i = 0; i < n; i++){
	cin>>input[i];
	freq[input[i]]++;
}
int fact[10];
fact[0]=0;
fact[1]=1;
for(int i = 2 ; i < 10 ;i++)
{
	fact[i] = (i) * fact[i-1];
}
int ans = countnumbers(input, fact, freq, n);
cout<<ans<<endl;
}
