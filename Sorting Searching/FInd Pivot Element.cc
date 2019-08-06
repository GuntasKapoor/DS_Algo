// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int FindPivot(int array[1],int s,int e){
	while(s<=e){
		int mid = (s+e)/2;
		if(array[mid]<array[mid-1]){
			return array[mid-1];
		}
		else if(array[mid]>array[mid+1]){
			return array[mid];
		}
		else if(array[s]<array[mid]){
			s = mid + 1;
		}
		else if(array[e]>array[mid]){
			e = mid - 1;
		}
	}

}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int array[100];
int N;
cin>>N;
for(int i=0;i<N;i++){
	cin>>array[i];
}
int ans = FindPivot(array,0,N-1);
cout<<ans<<endl;
}