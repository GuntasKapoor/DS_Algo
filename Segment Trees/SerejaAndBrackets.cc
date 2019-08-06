// Problem Link https://codeforces.com/contest/380/problem/C
// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;


struct Node{

	int curr=0,leftbrackets=0,rightbrackets=0;
};

char str[1000005];
Node segtree[4*1000005+1];


inline void BuildTree(Node segtree[], string str, int ss,int se,int idx){
	if(ss==se){
		segtree[idx].curr=0;
		if(str[ss]=='('){
			segtree[idx].leftbrackets=1;
			segtree[idx].rightbrackets=0;
		}
		else{
			segtree[idx].leftbrackets=0;
			segtree[idx].rightbrackets=1;
		}
		return;
	}
	int mid = (ss + se)>>1;
	BuildTree(segtree, str, ss,mid,2*idx);
	BuildTree(segtree, str,mid + 1, se, 2*idx + 1);
	int temp = min(segtree[2*idx].leftbrackets , segtree[2*idx + 1].rightbrackets);
	segtree[idx].curr = segtree[2*idx].curr + segtree[2*idx + 1].curr + 2*temp;
	segtree[idx].leftbrackets = segtree[2*idx].leftbrackets + segtree[2*idx + 1].leftbrackets - temp;
	segtree[idx].rightbrackets = segtree[2*idx].rightbrackets + segtree[2*idx + 1].rightbrackets - temp;
	return;
}

inline Node query(Node segtree[],int left,int right,int ss,int se, int idx){
// complete Overlap
	if(left<=ss && right>=se){
		return segtree[idx];;
	}

// No overlap;
	if(left>se || right<ss){
		Node a;
		return a;
	}


	int mid = (ss + se)>>1;
	Node l=query(segtree, left , right, ss, mid , 2*idx);
	Node r=query(segtree, left, right, mid + 1, se, 2*idx + 1);
	Node ans;
	int temp = min(l.leftbrackets , r.rightbrackets);
	ans.curr = l.curr + r.curr + 2*temp;
	ans.leftbrackets = l.leftbrackets + r.leftbrackets - temp;
	ans.rightbrackets = l.rightbrackets + r.rightbrackets - temp;
	return ans;
}


int main(){

scanf("%s",str);
int Q,l,r;
scanf("%d",&Q);
int len = strlen(str) - 1;
BuildTree(segtree,str,0,len,1);
while(Q--){
scanf("%d",&l);
scanf("%d",&r);
Node a = query(segtree,l-1,r-1,0,len,1);
printf("%d",a.curr);
printf("\n");
}
}