// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

// Question:- Given a set of numbers and a sum value we have to find..is there any subset of the set that adds up to this sum value

bool Recursive_Approach(int array[],int N,int sum){
if(sum==0){
	return true;
}
if(N==0){
	return false;
}

if(array[N-1]>sum){
	return Recursive_Approach(array,N-1,sum);
}
else{
	return Recursive_Approach(array,N-1,sum-array[N-1]) || Recursive_Approach(array,N-1,sum);
}
}
// Time Complexity:- O(N^2)
int BottomUp(int setofNumbers[],int N,int sum){
	int dp[sum + 1][ N+1 ];
	// we are taking sum + 1 and N+1 here because we need to fill values correspondng to sum=0 and N=0(empty set) also..!
	for(int i=0;i<=N;i++){
		dp[0][i]=1;
	}
	for(int i=1;i<=sum;i++){
		dp[i][0]=0;
	}
	for(int i=0;i<=sum;i++){
		for(int j=1;j<=N;j++){
			if(i<setofNumbers[j-1]){
				dp[i][j]=dp[i][j-1];
			}
			else{
				dp[i][j]=dp[i][j-1]||dp[i-setofNumbers[j-1]][j];
			}
		}
	}
// Printing dp table:-
	// for(int i=0;i<=sum;i++){
	// 	for(int j=0;j<=N;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// return dp[sum][N];
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N;
cin>>N;
int setofNumbers[100];
for(int i=0;i<N;i++){
	cin>>setofNumbers[i];
}
int sum;
cin>>sum;
// Recursive_Approach(setofNumbers,N,sum)?cout<<"True"<<endl:cout<<"False"<<endl;
if(BottomUp(setofNumbers,N,sum)){
	cout<<endl;
	cout<<"True"<<endl;
}
else{
	cout<<"False";
}
}