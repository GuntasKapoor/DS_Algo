// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;


long long int BuildSegTree(long long int array[],long long int segtree[],long long int ss,long long int se,long long int si){

	if(ss==se){
		segtree[si]=array[ss];
		return array[ss];
	}

	long long int mid=(ss+se)/2;
	long long int left=BuildSegTree(array,segtree,ss,mid,2*si+1);
	long long int right=BuildSegTree(array,segtree,mid+1,se,2*si+2);
	return segtree[si]=max(left+right,max(right,left));
}

long long int RangeQuery(long long int array[],long long int segtree[],long long int ss,long long int se,long long int si,long long int l,long long int r){
	if(l<=ss && r>=se){
		return segtree[si];
	}
	if(l>se || r<ss){
		return -1;
	}
	long long int mid=(ss+se)/2;
	long long int left=BuildSegTree(array,segtree,ss,mid,2*si+1);
	long long int right=BuildSegTree(array,segtree,mid+1,se,2*si+2);
	return max(left,right);
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

long long int N;
cin>>N;
long long int array[50001];
for(long long int i=0;i<N;i++){
	cin>>array[i];
}
long long int M;
long long int segtree[200004];
cin>>M;
BuildSegTree(array,segtree,0,N-1,0);
while(M--){
	long long int x,y;
	cin>>x>>y;
	cout<<RangeQuery(array,segtree,0,N-1,0,x-1,y-1)<<endl;
}
}O