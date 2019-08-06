#include <bits/stdc++.h>
using namespace std;
bool func(int i,int j){
    return i>j;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int k1,k2,k3;
	    cin>>k1>>k2>>k3;
	    int array[10000];
	    for(int i=0;i<N;i++){
	        cin>>array[i];
	}
	vector<int> v;
	    for(int i=0;i<N;i++){
	        for(int j=i;j<N;j++){
	            int sum=0;
	            for(int k=i;k<=j;k++){
	                sum+=array[k];
	            }
	            v.push_back(sum);
	        }
	    }
	    sort(v.begin(),v.end(),func);
	    cout<<v[k1-1]<<" "<<v[k2-1]<<" "<<v[k3-1]<<endl;
	}
	return 0;
}
