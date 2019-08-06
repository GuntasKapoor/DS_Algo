// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int constructSTUtil(int arr[],int st[],int ss,int se,int si){
    if(ss==se){
        st[si]=arr[ss];
        return arr[ss];
    }
    int mid=(ss+se)/2;
    return st[si]=min(constructSTUtil(arr,st,ss,mid,2*si+1),constructSTUtil(arr,st,mid+1,se,2*si+2));
}

int *constructST(int arr[],int n)
{
  int *stree=new int[2*n + 1];
  constructSTUtil(arr,stree,0,n-1,0);
  return stree;
}
int RMQUtil(int st[],int ss,int se,int si,int l,int r){
    if(l<=ss && r>=se){
        return st[si];
    }   
    if(l>se || r<ss){
        return INT_MAX;
    }
    int mid=(ss+se)/2;
    return min(RMQUtil(st,ss,mid,2*si+1,l,r),RMQUtil(st,mid+1,se,2*si+2,l,r));
}
int RMQ(int st[] , int n, int a, int b)
{
    int ans=RMQUtil(st,0,n-1,0,a,b);
    return ans;
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
int *segtree=new int[2*N + 1];
segtree=constructST(inp,N);
int l,r;
cin>>l>>r;
cout<<RMQ(segtree,N,l,r);
}