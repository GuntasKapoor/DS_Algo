// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int T;
cin>>T;
while(T--){
	int N;
	cin>>N;
	int final[26]={0};
	for(int i=0;i<N;i++){
		string s1;
		cin>>s1;
		int len=s1.length();
		int util[26]={0};
		if(i==0){
			for(int j=0;j<len;j++){
				final[s1[j]-'a']=1;
				util[s1[j]-'a']=1;
			}
		}
		else{
			for(int j=0;j<len;j++){
				util[s1[j]-'a']=1;
			}
			for(int j=0;j<26;j++){
				final[j]&=util[j];
			}
		}
		}
	int ans=0;
	for(int i=0;i<26;i++){
		if(final[i]>0){
			ans++;
		}
	}
	cout<<ans<<endl;
}
}