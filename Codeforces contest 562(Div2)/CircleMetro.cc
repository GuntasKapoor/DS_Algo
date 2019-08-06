
 // Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N,a,b,x,y;
cin>>N>>a>>x>>b>>y;
while(true){
	if(a==10){
	    a=1;
	}
	else{
	    a++;
	}
	if(b==1){
	    b=10;
	}
	else{
	    b--;
	}
	if(a==b){
		cout<<"YES"<<endl;
		break;
	}
	if(a>=x){
		cout<<"NO"<<endl;
		break;
	}
	if(b<=y){
		cout<<"NO"<<endl;
		break;
	}
}
}