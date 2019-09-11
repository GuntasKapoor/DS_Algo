#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    
    while(T--){
        set<int, greater<int>> s;
        int N, K;
        cin>>N>>K;
        vector<int> input(10000000);
        for(int i = 0; i < N; i++){
            cin>>input[i];
        }
        
        for(int i = 0; i < K; i++){
            s.insert(input[i]);
        }
        
        vector<int> output;
        output.push_back(*s.begin());
        for(int i = K; i < N; i++){
            s.erase(s.find(input[i - K]));
            s.insert(input[i]);
            output.push_back(*s.begin());
        }
        for(int i = 0; i < output.size(); i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
    }

	return 0;
}