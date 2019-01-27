// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
// Given a set of n elements, find number of ways of partitioning it.
// Examples:

// Input:  n = 2
// Output: Number of ways = 2
// Explanation: Let the set be {1, 2}
//             { {1}, {2} } 
//             { {1, 2} }

// Input:  n = 3
// Output: Number of ways = 5
// Explanation: Let the set be {1, 2, 3}
//              { {1}, {2}, {3} }
//              { {1}, {2, 3} }
//              { {2}, {1, 3} }
//              { {3}, {1, 2} }
//              { {1, 2, 3} }.

// Question Source:- GeeksforGeeks

// The answer to this Question is Bell Numbers..!
// Below series of Numbers is Bell numbers
// 1
// 1 2
// 2 3 5
// 5 7 10 15
// 15 20 27 37 52

// First element of every ith row gives the number of Partition a set of length i can have(i starts from 0).
// for eg a set of 4 element can have total of 15 partitions  of different sizes

// it is called bell no because the distribution of these numbers are in bell shaped..
// for eg Suppose you want to find partitions of size 1 of a set of N elements i.e. if N=4,  the size 1 partition would be {1,2,3,4}
// (no of ways to do this is 1) and that of size 4 would be {1,2,3,4}(No of ways to do this is also 1)

int getBellNumber(int N){
	int bell[100][100]={0};
	bell[0][0]=1;
	for(int i=1;i<=N;i++){
		for(int j=0;j<=i;j++){
			if(j==0){
				bell[i][j]=bell[i-1][i-1];
			}
			else{
				bell[i][j]=bell[i-1][j-1] + bell[i][j-1];
			}
		}
	}
	return bell[N][0];
}



int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int N;
cin>>N;
int partitions=getBellNumber(N);
cout<<partitions<<endl;  //Prints the Number of Partitions that a set of number N can have..!
}