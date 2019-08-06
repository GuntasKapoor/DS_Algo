#include <bits/stdc++.h>
using namespace std;
bool primes[100000000];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=4;i<100000000;i++){
		if(i%2!=0)
		 primes[i]=true;
		else
			primes[i]=false;
	}
	primes[0]=primes[1]=false;
	int N=sqrt(100000000);
	for(int i=3;i<=N;i+=2){
		if(primes[i]){
			for(int j=i*i;j<100000000;j+=i){
				primes[j]=false;
			}
		}
	}
	vector<long long int> primeNo(5000000);
	for(int i=0;i<100000000;i+=2){
		if(primes[i]==true){
			primeNo.push_back(i);
		}
	}
	
	int Q;
	cin>>Q;
	while(Q--){
		int q;
		cin>>q;
		cout<<primeNo[q-1]<<endl;
	}

	return 0;
}