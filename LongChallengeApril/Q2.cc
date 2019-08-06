// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;



int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

long long int T;
cin>>T;
while(T--){
	string str;
	long long N;
	char c;
	cin>>N;
	cin>>str;
	cin>>c;
	long long int totalcount = 0;
	long long int count=0;
	for(long long int i=0;i<N;i++){
		if(str[i]==c){
			totalcount+=(count*(count + 1))/2;
			count=0;
		}
		else{
		count++;
	}
	}
	if(count!=0){
		totalcount+=(count*(count + 1))/2;
	}
	long long int totalsubstrings = (N*(N+1))/2;
	long long int ans = totalsubstrings - totalcount;
	cout<<ans<<endl;
}
}