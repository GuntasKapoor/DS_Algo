#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
		int N,C;
		cin>>N>>C;
		int array[1000001];

		for(int i=0;i<N;i++){
			cin>>array[i];
		}
		sort(array,array+N);
		int mini = array[0];
		int maxi = array[N-1];
		maxi = maxi-mini;
		mini=INT_MIN;
		for(int i=0;i<N-1;i++){
			mini = min(mini,array[i+1]-array[i]);
		}
		int ans;
		while(mini<=maxi){
			int mid = (mini+maxi)/2;
			int j = 0;
			int cows = 1;
			for(int i=0;i<N;i++){
				if(array[i]-array[j]>=mid){
					cows ++;
					j=i;
				}
			}
			if(cows >= C){
				ans = mid;
				mini = mid + 1;
			}
			else{
				maxi = mid - 1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}