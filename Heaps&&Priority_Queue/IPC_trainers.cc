// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


// Question Link:- https://www.codechef.com/JULY17/problems/IPCTRAIN

class Trainer{
public:
	int day,lectures,sadness,index;

	Trainer(int D,int T,int S,int idx){
		day=D;
		lectures=T;
		sadness=S;
		index=idx;
	}
};

class compare{
public:
bool operator()(Trainer A,Trainer B){
	return A.sadness<B.sadness;
}
};


int Sadness(int N,int D,int Di[],int Ti[],int Si[]){
	vector<Trainer> array(N,Trainer(0,0,0,0));
	for(int i=0;i<N;i++){
		Trainer A(Di[i],Ti[i],Si[i],i);
		array[i]=A;
	}
	int totalsadness=0;
	int day=1;
	while(day<=D){
		priority_queue<Trainer,vector<Trainer>,compare> pq;
		for(int j=0;j<N;j++){
			if(array[j].day<=day && array[j].lectures>0){
				pq.push(array[j]);
			}
		}
		if(pq.empty()!=true)
		{
			array[pq.top().index].lectures-=1;
	}
	day++;
}
	for(int i=0;i<N;i++){
		if(array[i].lectures>0){
			totalsadness+=(array[i].lectures*array[i].sadness);
		}
		// cout<<array[i].day<<" "<<array[i].lectures<<" "<<array[i].sadness<<endl;
	}
	return totalsadness;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N,D;
int Di[100000],Ti[100000],Si[100000];
int T;
cin>>T;
while(T--){
	cin>>N>>D;
	for(int i=0;i<N;i++){
		cin>>Di[i]>>Ti[i]>>Si[i];
	}
	int ans=Sadness(N,D,Di,Ti,Si);
	cout<<ans<<endl;
}

}