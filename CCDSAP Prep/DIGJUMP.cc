#include <bits/stdc++.h>
using namespace std;

int main() {
	
    string s;
    cin>>s;
    
    int visited[100001] = {0};
    vector<int> Indices[10];
    
    for(int i = 0; i < s.length(); i++){
        Indices[s[i] - '0'].push_back(i);
    }
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    int dist[100001];
    dist[0] = 0;
    while(!q.empty()){
        int front = q.front();
        if(front == s.length() - 1){
            break;
        }
        q.pop();
        int node = s[front] - '0';
        
        for(int i = 0; i < Indices[node].size(); i++){
            if(!visited[Indices[node][i]]){
                visited[Indices[node][i]] = 1;
                q.push(Indices[node][i]);
                dist[Indices[node][i]] = dist[front] + 1;
            }
        }
        Indices[node].clear();
        if(front - 1 >= 0 && !visited[front - 1]){
            visited[front - 1] = 1;
            q.push(front - 1);
            dist[front - 1] = dist[front] + 1;
        }
        
        if(front + 1 < s.length() && !visited[front + 1]){
            visited[front + 1] = 1;
            q.push(front + 1);
            dist[front + 1] = dist[front] + 1;
        }
    }
    cout<<dist[s.length() - 1]<<endl;
    // for(int i = 0; i < s.length(); i++){
    //     cout<<dist[i]<<" ";
    // }
	return 0;
}
