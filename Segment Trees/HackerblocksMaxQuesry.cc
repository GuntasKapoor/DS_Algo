// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

void BuildSegtree(int *segtree,int *a,int s,int e,int idx){
	if(s==e){
		segtree[idx]=a[s];
		return;
	}

	int mid = (s+e)/2;
	BuildSegtree(segtree,a,s,mid,2*idx);
	BuildSegtree(segtree,a,mid+1,e,2*idx+1);
	segtree[idx]=min(segtree[2*idx],segtree[2*idx+1]);
	return;
}

int Query(int *segtree,int s,int e,int L,int R,int K,int idx){
	if(L>e || R<s){
		return 0;
	}
	if(s==e && L>=s<=R){
		if(segtree[idx]>=K){
			return 1;
		}
		else{
			return 0;
		}
	}
	int mid=(s+e)/2;
	int left = Query(segtree,s,mid,L,R,K,2*idx);
	int right = Query(segtree,mid+1,e,L,R,K,2*idx+1);
	return left+right;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N;
cin>>N;
int array[100000];
for(int i=0;i<N;i++){
	cin>>array[i];
}
int *segtree=new int[4*N+1];
BuildSegtree(segtree,array,0,N-1,1);
int Q;
cin>>Q;
int L,R,K;
while(Q--){
cin>>L>>R>>K;
cout<<Query(segtree,0,N-1,L-1,R-1,K,1)<<endl;
}

}