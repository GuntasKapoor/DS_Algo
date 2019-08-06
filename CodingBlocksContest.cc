#include<bits/stdc++.h>
using namespace std;
void pintallcombinations(int array[],int array2[],int i,int j,int num,int rednum,int &count,int N){
   if(rednum<0){
       return;
   }
   if(rednum==0){
       for(int k=0;k<j && array2[k]!=0 ;k++){
           cout<<k<<" ";
       }
       count+=1;
       cout<<endl;
       return;
   }
   if(i>N || j>N){
   	return;
   }
   
   array2[j]=array[i];
   pintallcombinations(array,array2,i+1,j+1,num,rednum-array[i],count,N);
   array2[j]=0;
   pintallcombinations(array,array2,i+1,j,num,rednum,count,N);
}

int main() {
	int A,B;
	cin>>A>>B;
	int N=pow(A,(double)1/B);
	cout<<N<<endl;
	int array[N+2];
	for(int i=0;i<=N+1;i++){
	    array[i]=(int)pow(i,B);
	 	cout<<array[i]<<endl;
	}
    int array2[N+2];
    int count=0;
    pintallcombinations(array,array2,0,0,A,A,count,N+2);
    cout<<count<<endl;
	
}