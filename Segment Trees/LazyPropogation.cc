// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;

// The Idea of Lazy Propogation is that we dont update the value of all the nodes of the segment tree and will 
// update till the complete overlap and then assign a lazy value to its children
void BuildSegtree(int *segtree,int * lazy,int *inp,int s,int e, int idx){
	lazy[idx] = 0;
	if(s==e){
		segtree[idx]=inp[s];
		return;
	}

	int mid = (s+e)/2;
	BuildSegtree(segtree,lazy,inp,s,mid,2*idx);
	BuildSegtree(segtree,lazy,inp,mid + 1,e,2*idx + 1);
	segtree[idx] = min(segtree[2*idx],segtree[2*idx + 1]);
	return;
}


void updateRange(int *segtree, int increment, int s,int e,int l,int r, int idx){
	// No Overlap
	if(l>e || r<s){
		return;
	}
	if(s==e){
		segtree[idx] += increment;
		return;
	}
	int mid = (s + e)/2;
	updateRange(segtree,increment,s,mid,l,r,2*idx);
	updateRange(segtree, increment,mid+1,e,l,r,2*idx + 1);
	segtree[idx] = min(segtree[2*idx],segtree[2*idx + 1]);
	return;
}

int query(int *segtree, int s,int e,int l,int r, int idx){
	// No overlap:
	if(l>e || r<s){
		return INT_MAX;
	}
	// Complete Overlap;
	if(s>=l && e<=r){
		return segtree[idx];
	}

	// Partial Overlap;
	int mid = (s + e)/2;
	int left = query(segtree, s, mid, l, r, 2*idx);
	int right = query(segtree, mid+1 , e, l ,r , 2*idx + 1);
	return min(left,right);
}

void LazyUpdate(int* segtree,int *lazy,int increment,int s,int e,int l,int r,int idx){
	if(l>e || r<s){
		return;
	}
	if(lazy[idx]!=0){
		segtree[idx] += lazy[idx];
		if(s!=e){
			lazy[2*idx] += lazy[idx];
			lazy[2*idx + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}

	if(s>=l && e<=r){
		segtree[idx]+=increment;
		if(s!=e){
			lazy[2*idx] += increment;
			lazy[2*idx + 1] += increment;
		}
		return;
	}
	int mid = (s + e)/2;
	LazyUpdate(segtree, lazy, increment, s, mid, l,r,2*idx);
	LazyUpdate(segtree,lazy,increment,mid + 1,e,l,r,2*idx + 1);
	segtree[idx]=min(segtree[2*idx],segtree[2*idx + 1]);
	return;


}

int LazyQuery(int *segtree, int *lazy,int l,int r,int s,int e,int idx){
	// No Overlap;
	if(l>e || r<s){
		return INT_MAX;
	}
	if(lazy[idx]!=0){
	segtree[idx]+=lazy[idx];
	if(s!=e){
		lazy[2*idx]+=lazy[idx];
		lazy[2*idx]+=lazy[idx];
	}
	lazy[idx]=0;
}
	// Complete Overlap;
	if(s>=l && e<=r){
		return segtree[idx];
	}

	int mid = (s+e)/2;
	int left = LazyQuery(segtree, lazy , l , r, s, mid , 2*idx );
	int right = LazyQuery(segtree,lazy ,l,r,mid+1,e, 2*idx + 1);
	return min(left,right);

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N;
cin>>N;
int arr[1000];
for(int i=0;i<N;i++){
	cin>>arr[i];
}
int *lazy=new int[4*N + 1];
int *segtree = new int[4*N + 1];
BuildSegtree(segtree,lazy,arr,0,N-1,1);
int l,r;
cin>>l>>r;
int increment;
cin>>increment;
LazyUpdate(segtree,lazy,increment,0,N-1,l,r,1);
int ql,qr;
cin>>ql>>qr;
cout<<LazyQuery(segtree,lazy,ql,qr,0,N-1,1);
}