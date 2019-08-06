// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int LIS(int array[],int i,int N,int prev){
	if(i==N){
		return 0;
	}
	int q1=-1;
	if(array[i]>prev){
		q1=1+LIS(array,i+1,N,array[i]);
	}
	int q2=LIS(array,i+1,N,prev);
	return max(q1,q2);
}

int dpSolution(int array[],int N){
	int dp[N];
	for(int i=0;i<N;i++){
		dp[i]=1;
	}
	for(int i=1;i<N;i++){
		int maxval=0;
		for(int j=0;j<i;j++){
			if(array[j]<array[i]){
				maxval=max(maxval,dp[j]);
			}
		}
		dp[i]+=maxval;
	}
	int ans=-1;
	for(int i=0;i<N;i++){
		ans=max(ans,dp[i]);
	}
	return ans;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N,T;
cin>>T;
while(T--){
cin>>N;
int array[100];
for(int i=0;i<N;i++){
	cin>>array[i];
}
// cout<<LIS(array,0,N,INT_MIN);
cout<<dpSolution(array,N)<<endl;
}

}