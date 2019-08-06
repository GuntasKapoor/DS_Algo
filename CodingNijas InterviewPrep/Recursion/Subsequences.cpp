// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int subs(string input, string output[]){
// Base Case
	if(input.size()==0){
		output[0] = "";
		return 1;
	}

	string smallstring = input.substr(1);
	int countsmallstring = subs(smallstring, output);

	for(int i = 0;i < countsmallstring ; i++){
		output[i+countsmallstring] = input[0] + output[i];
	}
	return 2*countsmallstring;
}



int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

string input;
cin>>input;
int lenoutput = pow(2,input.length());
string *output = new string[lenoutput];
int countsubseq  = subs(input,output);

for(int i = 0; i < countsubseq ; i++){
	cout<<output[i]<<endl;
}
}