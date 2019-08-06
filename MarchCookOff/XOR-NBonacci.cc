#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin>>N>>Q;
    int array[100001];
    int XOR=0;
    int xo[100001];
    for(int i=0;i<N;i++){
        cin>>array[i];
        XOR=XOR^array[i];
        xo[i]=XOR;
    }
    array[N]=XOR;
    int Queries[100001];
    while(Q--){
        long long int q;
        cin>>q;
        int mod = q%(N+1);
        int ans=0;        
        cout<<xo[mod-1]<<endl;
    }
    
    return 0;
}
