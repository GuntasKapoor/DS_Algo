// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;

vector<long long int> fib;

long long int gcd(long long int a,long long int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

void BuildSegtree(long long int *segtree,long long int *a,long long int s,long long int e,long long int idx){
	if(s==e){
		segtree[idx]=a[s];
		return;
	}

	long long int mid=(s+e)/2;
	BuildSegtree(segtree,a,s,mid,2*idx);
	BuildSegtree(segtree,a,mid+1,e,2*idx+1);
	segtree[idx]=gcd(segtree[2*idx],segtree[2*idx]+1);
	return;
}

long long int Query(long long int *segtree, long long int L,long long int R,long long int s,long long int e,long long int idx){
	if(L>e || R<s){
		return 0;
	}
	if(s>=L && e<=R){
		return segtree[idx];
	}
	long long int mid = (s+e)/2;
	long long int left = Query(segtree,L,R,s,mid,2*idx);
	long long int right = Query(segtree,L,R,mid+1,e,2*idx + 1);
	if(left>right){
		return gcd(left,right);
	}
	else{
		return gcd(right,left);
	}
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

long long int N,Q;
cin>>N>>Q;
long long int array[100000];
long long int maxi=INT_MIN;
for(long long int i=0;i<N;i++){
	cin>>array[i];
	maxi=max(array[i],maxi);
}

fib.push_back(0);
fib.push_back(1);
for(long long int i=2;i<=maxi;i++){
	fib.push_back(fib[i-1] + fib[i-2]);
}
for(long long int i=0;i<N;i++){
	array[i]=fib[array[i]];
	cout<<array[i]<<" ";
}
long long int *segtree=new long long int[4*N+1];
BuildSegtree(segtree,array,0,N-1,1);
long long int L,R;
while(Q--){
cin>>L>>R;
cout<<Query(segtree,L-1,R-1,0,N-1,1)%(1000000007)<<endl;
}
}