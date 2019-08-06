// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N; cin>>N;
long long arr[100000];
for(int i=0;i<N;i++){
	cin>>arr[i];
}
sort(arr,arr + N);
int i = N-2;
while(arr[i] == arr[i+1]){
	i--;
}
if(i==-1){
	cout<<0<<endl;
}
else{
	cout<<arr[i]<<endl;
}
}