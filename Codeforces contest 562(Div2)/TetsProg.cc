#include <bits/stdc++.h>
using namespace std;

int BFS(vector<int> * AdjList, int src, int dest){
    int dist[100001] = {0};
    int visited[100001] = {0};
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    visited[src] = 1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        if(front == dest){
            return dist[dest];
        }

        for(int i = 0; i < AdjList[front].size(); i++){
            if(!visited[AdjList[front][i]]){
                visited[AdjList[front][i]] = 1;
                dist[AdjList[front][i]] = dist[front] + 1;
                q.push(AdjList[front][i]);
                if(AdjList[front][i] == dest){
                    return dist[AdjList[front][i]];
                }
            }
        }
    }
}


int main() {
    string s;
    cin>>s;
    vector<int> *AdjList = new vector<int>[s.size() + 1];
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < s.length() - 1; i++){
        AdjList[i].push_back(i + 1);
        AdjList[i + 1].push_back(i);
        int a = s[i] - '0';
        mp[a].push_back(i);
    }
    mp[s[s.length() - 1] - '0'].push_back(s.length() - 1);
    for(int i = 0; i <= 9; i++){
        if(mp[i].size() >= 2){
            for(int j = 0; j < mp[i].size() - 1; j++){
                for(int k = j + 1; k < mp[i].size(); k++){
                    if(mp[i][j] + 1!= mp[i][k]){
                        AdjList[mp[i][j]].push_back(mp[i][k]);
                        AdjList[mp[i][k]].push_back(mp[i][j]);
                    }
                }
                // cout<<mp[i][j]<<" ";
            }
        }
            // cout<<endl;
        }
    
    int steps = BFS(AdjList, 0, s.length() - 1);
    cout<<steps<<endl;
	return 0;
}
