// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	long long int prefixSum,suffixSum, maxsum, sum;
	Node(){

	}
};
map<int,bool> visited;
void BuildTree(Node * segtree, long long int *inp,long long int s,long long int e,long long int idx){
	if(s==e){
		if(!visited[inp[s]]){
		segtree[idx].prefixSum=segtree[idx].suffixSum=segtree[idx].maxsum=segtree[idx].sum=inp[s];
	}
		else{
		segtree[idx].prefixSum=segtree[idx].suffixSum=segtree[idx].maxsum=segtree[idx].sum=INT_MIN;
		}

		return;
	}

	long long int mid = (s+e)/2;
	BuildTree(segtree,inp, s, mid, 2*idx);
	BuildTree(segtree, inp, mid+1, e,2*idx + 1);
	segtree[idx].prefixSum = max(segtree[2*idx].prefixSum, segtree[2*idx].sum + segtree[2*idx + 1].prefixSum);
	segtree[idx].suffixSum = max(segtree[2*idx +1].suffixSum, segtree[2*idx].suffixSum + segtree[2*idx + 1].sum);
	segtree[idx].maxsum = max(max(segtree[2*idx].maxsum,segtree[2*idx + 1].maxsum),segtree[2*idx].suffixSum + segtree[2*idx+1].prefixSum);
	segtree[idx].sum = segtree[2*idx].sum + segtree[2*idx + 1].sum;
	return;
}

Node Query(Node * segtree,long long int s,long long int e,long long int L,long long int R,long long int idx){
	if(L>e || R<s){
		Node a;
		a.prefixSum=a.suffixSum=a.maxsum=a.sum=INT_MIN;
		return a;
	}
	
	if(L<=s && R>=e){
		return segtree[idx];
	}
	long long int mid = (s+e)/2;
	Node left=Query(segtree, s, mid, L, R,2*idx);
	Node right=Query(segtree, mid + 1, e,L, R, 2*idx+1);
	Node temp;
	temp.prefixSum = max(left.prefixSum, left.sum + right.prefixSum);
	temp.suffixSum = max(right.suffixSum, left.suffixSum + right.sum);
	temp.maxsum = max(max(left.maxsum,right.maxsum),left.suffixSum + right.prefixSum);
	temp.sum = left.sum + right.sum;
	return temp;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

long long int N;
cin>>N;
long long int array[500000];
Node * segtree=new Node[4*N+1];
for(long long int i=0;i<N;i++){
	cin>>array[i];
}
BuildTree(segtree,array,0,N-1,1);
long long int L,R,Q;
cin>>Q;
while(Q--){
	cin>>L>>R;
	Node ans = Query(segtree,0,N-1,L-1,R-1,1);
	cout<<max((long long int)0,ans.maxsum)<<endl;
}

}