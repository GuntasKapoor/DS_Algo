// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int subset(int input[], int n, int output[][20]) {
    // Write your code here
    if(n==0){
        output[0][0] = 0;
        return 1;
    }
    
    int ans = subset(input + 1, n - 1, output);
    
    for(int i = 0 ; i < ans; i++){
            output[ans + i][0] = output[i][0] + 1;
            output[ans + i][1] = input[0];
            int size = output[i][0];
            for(int j = 0 ; j < size ; j++){
                output[i + ans][j + 2] = output[i][j+1];
            }
    }
    return 2*ans;          
}



int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;
int input[100];
for(int i = 0 ; i < n; i++){
	cin>>input[i];
}
int output[20][20] = {};
int size = subset(input, n, output);
for (int i = 0; i < size; i++){
	for(int j = 0; j < output[i][0]; j++){
		cout<<output[i][j]<<" ";
	}
	cout<<endl;
}
}