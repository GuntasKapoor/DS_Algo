// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


// Given an array of numbers we have to sort it like a Wave..!
void WaveSort(int array[],int N){
	for(int i=0;i<N;i+=2){
		if(i==0){
			if(array[i]<array[i+1]){
				swap(array[i],array[i+1]);
			}
		}
		else if(i==N-1){
			if(array[i]<array[i-1]){
				swap(array[i],array[i-1]);
			}
		}
		else{
			if(array[i]<array[i-1]){
				swap(array[i],array[i-1]);
			}
			if(array[i]<array[i+1]){
				swap(array[i],array[i+1]);
			}
		}
	}
	return;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int array[100];
int N;
cin>>N;
for(int i=0;i<N;i++){
	cin>>array[i];
}
WaveSort(array,N);
cout<<endl;
for(int i=0;i<N;i++){
	cout<<array[i]<<" ";
}
}