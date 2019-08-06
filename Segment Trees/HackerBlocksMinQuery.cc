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

int PrintMinElement(int *segtree,int s,int e,int qs,int qe,int idx){
	if(qs>e || qe<s){
		return INT_MAX;
	}
	else if(s>=qs && e<=qe){
		// Complete Overlap
		return segtree[idx];
	}
	int mid = (s+e)/2;
	// Partial Overlap
	int left = PrintMinElement(segtree,s,mid,qs,qe,2*idx);
	int right = PrintMinElement(segtree,mid+1,e,qs,qe,2*idx+1);
	return min(left,right);
}

void Update_value(int *segtree,int s,int e,int X,int Y,int idx){
	if(X>e || X<s){
		return;
	}
	if(s==e && s==X){
		segtree[idx]=Y;
		return;
	}
	int mid = (s+e)/2;
	Update_value(segtree,s,mid,X,Y,2*idx);
	Update_value(segtree,mid+1,e,X,Y,2*idx+1);
	segtree[idx]=min(segtree[2*idx],segtree[2*idx+1]);
	return;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N,Q;
int array[100000];
cin>>N>>Q;
for(int i=0;i<N;i++){
cin>>array[i];	
}
int *segtree = new int[4*N+1];
BuildSegtree(segtree,array,0,N-1,1);
// for(int i=1;i<4*N+1;i++){
// 	cout<<segtree[i]<<" ";
// }
while(Q--){
	int a,b,c;
	cin>>a>>b>>c;
	if(a==1){
		cout<<PrintMinElement(segtree,0,N-1,b-1,c-1,1)<<endl;		
	}
	else{
		Update_value(segtree,0,N-1,b-1,c,1);
	}
}

}