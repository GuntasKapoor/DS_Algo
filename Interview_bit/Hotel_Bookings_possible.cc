// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int,int>> v;
    for(int i=0;i<arrive.size();i++){
        v.push_back(make_pair(arrive[i],depart[i]));
    }
    
    sort(v.begin(),v.end(),compare);
    K--;
    for(int i=1;i<arrive.size();i++){
        if(v[i-1].first>v[i-1].second){
            K++;
        }
        K--;
        if(K<0){
            return false;
        }
    }
    return true;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

}