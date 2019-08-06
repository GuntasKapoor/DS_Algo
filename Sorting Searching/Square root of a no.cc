// Guntas Singh
// Thapar University
#include <iostream>
using namespace std;



// First We will Apply binary search for finding the Integer Part..!

int integerPart(int s,int e,int no){
	int ans = -1;
	while(s<=e){
		int mid = (s+e)/2;
		if(mid*mid>no){
			e = mid-1;
		}
		else if(mid*mid<no){
			ans = mid;
			s = mid + 1;
		}
		else{
			return mid;
		}
	}
	return ans;
}


double squareRoot(int no, int precision){
	double root=0;
	int integer = integerPart(1,no,no);
	root += (double)integer;

	if(integer*integer==no){
		return root;
	}
	double inc = 1;
	while(precision--){
		inc/=10;
		for(double i = root;i<root+1;i+=inc){
			if((i*i)>no){
				root=(i-inc);
				break;
			}
		}
	}
	return root;
}

int main(){
int no,precision;
cin>>no>>precision;
double ans = squareRoot(no,precision);
cout<<"Square root is "<<ans;
	
}