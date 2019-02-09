// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

// Question:- GIven N cars and its cordinates, we have to find the K nearest cars..!

// if we do it by sorting an array--> Time complexity->O(NlogN)
// if we do usng heap--> Time complexity is O(N + KlogN)

class Car{
public: 
	int xcordinate,ycordinate,model;
	Car(int x,int y,int m){
		xcordinate=x;
		ycordinate=y;
		model=m;
	}
	int distance(){
		return xcordinate*xcordinate + ycordinate*ycordinate;
	}
};

class Compare{
public:
	// we have to overload () operator for compare functor of priority Queue..!
	bool operator()(Car A,Car B){
		return A.distance()>B.distance();
	}
};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
priority_queue<Car,vector<Car>,Compare> pq;
int N,K;
cin>>N>>K;
for(int i=0;i<N;i++){
int x,y;
cin>>x>>y;
Car A(x,y,i);
pq.push(A);
}
for(int i=0;i<K;i++){
	cout<<pq.top().model<<" "<<pq.top().xcordinate<<" "<<pq.top().ycordinate<<endl;
	pq.pop();
}

}