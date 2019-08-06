// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int constructSegTree(int inp[],int start,int end,int segtree[],int curidx){

	if(start==end){
		segtree[curidx]=inp[start];
		return inp[start];
	}

	int mid=(start+end)/2;
	segtree[curidx]=constructSegTree(inp,start,mid,segtree,2*curidx+1)+constructSegTree(inp,mid+1,end,segtree,2*curidx+2);
	return segtree[curidx];
}



int SumofRange(int segtree[],int left,int right,int start,int end,int curidx){
	if(left<=start && right>=end){
		return segtree[curidx];
	}

	if(left>end || right<start){
		return 0;
	}
	int mid=(start+end)/2;
	return SumofRange(segtree,left,right,start,mid,2*curidx+1) + SumofRange(segtree,left,right,mid+1,end,2*curidx + 2);
}

void Update_Value(int inp[],int segtree[],int idx,int start,int end,int diff,int curidx,int newele){
	if(idx<start || idx>end){
		return;
	}
	segtree[curidx]+=diff;
	if(start!=end){
	int mid=(start+end)/2;
	Update_Value(inp,segtree,idx,start,mid,diff,2*curidx+1,newele);
	Update_Value(inp,segtree,idx,mid+1,end,diff,2*curidx+2,newele);
}
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N;
cin>>N;
int inp[100];
for(int i=0;i<N;i++){
	cin>>inp[i];
}
int left,right;
cin>>left>>right;
int segtree[100]={0};   // its size would be=2*N - 1;
int cindex;
constructSegTree(inp,0,N-1,segtree,0);
// cout<<SumofRange(segtree,left,right,0,N-1,0)<<endl;
int newele,idx;
cin>>newele>>idx;
for(int i=0;i<3*N;i++){
	cout<<segtree[i]<<" ";
}
cout<<endl;
int diff=newele-inp[idx];
inp[idx]=newele;
Update_Value(inp,segtree,idx,0,N-1,diff,0,newele);
cout<<endl;
for(int i=0;i<3*N;i++){
	cout<<segtree[i]<<" ";
}
cout<<endl;
for (int i = 0; i < N; ++i)
{
	cout<<inp[i]<<" ";
}


cout<<SumofRange(segtree,left,right,0,N-1,0);
}