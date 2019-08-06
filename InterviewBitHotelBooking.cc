#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first > b.first){
        return true;
    }
    else if(a.first == b.first){
        return a.second < b.second;
    }
    return false;
}
vector<int> solve(string A, vector<string> &B) {
    unordered_map<string, bool> mp;
    
    for(int i = 0; i < A.length(); i++){
        string str = "";
        while(true){
            if(i == A.length()){
                break;
            }
            char a = A[i];
            if(a == '_'){
                break;
            }
            str+=a;
            i++;
        }
        mp[str] = true;
    }
    vector<pair<int,int>> nGoodWords;
    
    for(int i = 0; i < B.size(); i++){
        string a = B[i];
        int count = 0;
        for(int j = 0; j < a.length(); j++){
        string str = "";
        while(true){
            if(j == a.length()){
                break;
            }
            char c = a[j];
            if(c == '_'){
                break;
            }
            str+=c;
            j++;
        }
        if(mp.count(str) > 0){
            cout<<str<<endl;
            count++;
        }
        }
        nGoodWords.push_back(make_pair(count, i));
    }
    for(int i = 0; i < nGoodWords.size(); i++){
        cout<<nGoodWords[i].first<<" "<<nGoodWords[i].second<<endl;
    }
    sort(nGoodWords.begin(), nGoodWords.end(), compare);
    for(int i = 0; i < nGoodWords.size(); i++){
        cout<<nGoodWords[i].first<<" "<<nGoodWords[i].second<<endl;
    }
    vector<int> ans;
    for(int i = 0; i < nGoodWords.size(); i++){
        ans.push_back(nGoodWords[i].second);
    }
    return ans;
}

int main(){
    string a;
    cin>>a;
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    vector<int> ans = solve(a, arr);
}