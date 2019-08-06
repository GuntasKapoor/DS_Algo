#include <bits/stdc++.h>
using namespace std;

bool ispossible(long long int mid, vector<int>  C,long long int A){
    long long int noofpainters = 1;
    long long int cumulative = 0;
    for(int i=0;i<C.size();){
        cumulative += (long long int)C[i];
        if(cumulative>mid){
            noofpainters++;
            cumulative = 0;
        }
        else{
            i++;
        }
    }
    if(noofpainters <= A){
        return true;
    }
    return false;
}

int paint(int A, int B, vector<int> &C) {
    long long int mini = INT_MIN;
    long long int maxi = 0;
    for(int i=0;i<C.size();i++){
        mini = max(mini,(long long int)C[i]);
        maxi += (long long int)C[i];
    }
    long long int ans;
    while(mini<=maxi){
    long long int mid = (maxi+mini)/2;
    if(ispossible(mid,C,(long long int)A)){
        ans = mid%10000003;
        maxi = mid - 1;
    }
    else{
        mini = mid + 1;
    }
    }
    int final = (ans*B)%10000003;
    return final;
}


int main(){
vector<int> C;
int N;
cin>>N;
for(int i=0;i<N;i++){
	int a;
	cin>>a;
	C.push_back(a);
}
int A,B;
cin>>A>>B;
int ans = paint(A,B,C);
cout<<ans;
}