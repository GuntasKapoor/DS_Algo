// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;



int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

long long int N,K;
cin>>N>>K;
long long int input[200001];

for(long long int i = 0; i < N; i++){
	cin>>input[i];
}
sort(input, input + N);
long long int medianidx = (N/2);
long long int elements = 1;
long long int i = medianidx;
long long int sumadd = 0;
while(K!=0 && i < N - 1){
while(i < N - 1){
	if(input[i] == input[i + 1]){
		i++;
		elements++;
	}
	else{
		break;
	}
}
if(i == N - 1){
	break;
}
long long int operations = (input[i + 1] - input[i])*elements;
if(K >= operations){
	sumadd += (input[i + 1] - input[i]);
	elements++;
	K-=operations;
}
else{
	break;
}
i++;
}

sumadd += (K/elements);
cout<<input[medianidx] + sumadd<<endl;
}