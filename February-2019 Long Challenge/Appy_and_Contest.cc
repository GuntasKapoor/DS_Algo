// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
int maxi=-1;
int func(int start,int end,int a,int b,int r,int A,int B){
	if(start>end){
		maxi=max(maxi,a+b-r);
		return maxi;
	}
		int mid=(start + end)/2;
		if(mid%A==0 && mid%B!=0){
			a++;
			cout<<"aw"<<mid<<endl;
		}
		else if(mid%B==0 && mid%A!=0){
			b++;
			cout<<"BW"<<mid<<endl;
		}
		else if(mid%A==0 && mid%B==0){
			r++;
			cout<<"cw"<<mid<<endl;
		}
		func(start,mid-1,a,b,r,A,B);
		func(mid+1,end,a,b,r,A,B);
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int T;
cin>>T;
while(T--){
	int N,K,A,B;
	cin>>N>>A>>B>>K;
	int a=0,b=0,r=0;
	int start=1;
	int end=N;
	int ans=func(start,end,a,b,r,A,B);
	cout<<ans;
	if(ans<K){
		cout<<"Lose"<<endl;
	}
	else{
		cout<<"Win"<<endl;
	}
}


}