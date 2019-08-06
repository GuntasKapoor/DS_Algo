#include <bits/stdc++.h>
using namespace std;
bool compare(pair<string,pair<int,int>> a,pair<string,pair<int,int>>  b){
    if(a.second.second>b.second.second){
        return true;
    }
    if(a.second.second==b.second.second){
        return a.second.first>b.second.first;
    }
    return false;
}

int main(){
 int T;
 cin>>T;
 cin.ignore();
 while(T--){
     map<string,pair<int,int>> match;
     string str,hteam,ateam;
     int hscore,ascore; 
     for(int i=0;i<12;i++){
         getline(cin,str);
         stringstream ss(str);
         string word;
         int count = 0;
         while(ss>>word){
             if(count==0){
                hteam=word;
             }
             if(count==1){
                 hscore=stoi(word);
             }
             if(count==4){
                 ateam=word;
             }
             if(count==3){
                 ascore=stoi(word);
             }
             count++;
         }
         if(hscore>ascore){
            int oldscoreh=match[hteam].first;
            int oldptsh=match[hteam].second;
            match[hteam]=make_pair(oldscoreh+(hscore-ascore),oldptsh+3);
            int oldscorea=match[ateam].first;
            int oldptsa=match[ateam].second;
            match[ateam]=make_pair(oldscorea+(ascore-hscore),oldptsa);
         }
         else if(hscore<ascore){
            int oldscoreh=match[hteam].first;
            int oldptsh=match[hteam].second;
            match[hteam]=make_pair(oldscoreh+(hscore-ascore),oldptsh);
            int oldscorea=match[ateam].first;
            int oldptsa=match[ateam].second;
            match[ateam]=make_pair(oldscorea+(ascore-hscore),oldptsa+3);
         }
         else{
            int oldscoreh=match[hteam].first;
            int oldptsh=match[hteam].second;
            match[hteam]=make_pair(oldscoreh+(hscore-ascore),oldptsh+1);
            int oldscorea=match[ateam].first;
            int oldptsa=match[ateam].second;
            match[ateam]=make_pair(oldscorea+(ascore-hscore),oldptsa+1);
         }
         
     }
     vector<pair<string,pair<int,int>>> v;
     for(auto it=match.begin();it!=match.end();it++){
        v.push_back(make_pair(it->first,make_pair(it->second.second,it->second.first)));
     }
     sort(v.begin(),v.end(),compare);
     cout<<v[0].first<<" "<<v[1].first;

}
} 