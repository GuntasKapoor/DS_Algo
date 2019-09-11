// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;


bool helper(int c[], int e[], int a, int b, int slots, double s1, double s2){

	if(slots == 0){
		if(a <= s1 && b <= s2){
			// cout<<s1<<" "<<s2<<endl;
			return true;
		}
		else{
			cout<<s1<<" "<<s2<<endl;
			
			return false;
		}
	}

	    double v1, v2;
		for(double f = 0.00; f <= 1.00; f+=0.01){
			v1 = f*c[0];
			v2 = (1.00 - f)*e[0];
			bool ans = helper(c + 1, e + 1, a, b, slots - 1, s1 + v1, s2 + v2);
			if(ans){
				return true;
			}
		}

	return false;
}




int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int T;
cin>>T;
int cnt = 1;
while(T--){
	int days, slots;
	cin>>days>>slots;
	int c[100001];
	int e[100001];
	int a[100001];
	int b[100001];
	for(int i = 0; i < slots; i++){
		cin>>c[i]>>e[i];
	}
	for(int i = 0; i < days; i++){
		cin>>a[i]>>b[i];
	}
	string s = "";
	for(int i = 0; i < days; i++){
		bool ans = helper(c, e, a[i], b[i], slots, 0.00, 0.00);
		if(ans){
			s += 'Y';
		}
		else{
			s += 'N';
		}
	}
	cout<<"Case #"<<cnt<<": "<<s<<endl;
	cnt++;
}


}