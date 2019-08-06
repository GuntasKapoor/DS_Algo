// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
int k[100];
bool compare(int a,int b){
	return k[a]<k[b];
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int help[10];
for(int i=0;i<8;i++){
	cin>>k[i];
	help[i]=i;
}
sort(help,help+8,compare);
for (int i=0;i<8;i++){
	cout<<help[i]<<" ";
}

}