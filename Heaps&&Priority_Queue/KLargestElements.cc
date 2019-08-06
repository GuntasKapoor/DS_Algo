// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

// Question:- Given N no of elements, we havr to find K largest elements in the array of N elements..!

// Time complexity using sorting-->O(NlogN + K);
// Time complexity using min heap--> O(K) + O((N-K)LogK)

void KLargestElements(int N,int K,int array[]){
	priority_queue<int,vector<int>,greater<int>> pq;
	priority_queue<int>pq2; //max heap by default
	for(int i=0;i<K;i++){
		pq.push(array[i]);
	}

	for(int i=K;i<N;i++){
		if(array[i]>pq.top()){
			pq.pop();
			pq.push(array[i]);
		}
	}
	while(pq.empty()!=true){
		pq2.push(pq.top());
		pq.pop();
	}
	while(pq2.empty()!=true){
		cout<<pq2.top()<<" ";
		pq2.pop();
	}
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N,K,T;
cin>>T;
while(T--){
cin>>N>>K;
int array[100];
for(int i=0;i<N;i++){
	cin>>array[i];
}
KLargestElements(N,K,array);
cout<<endl;
}
}