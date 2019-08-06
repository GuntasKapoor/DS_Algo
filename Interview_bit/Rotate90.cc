// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


void rotate(int A[100][100],int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i][j]>=0){
			A[i][j]=-A[j][i];
			swap(A[i][j],A[j][i]);
		}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<(N/2);j++){
			swap(A[i][j],A[i][N-1-j]);
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i][j]<0){
				A[i][j]=-A[i][j];
			}
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}




int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

}