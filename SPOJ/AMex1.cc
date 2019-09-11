#include <bits/stdc++.h>

int DFS(vector<int> AdjList[], int visited[], int start){
    visited[start] = 1;
    int ans = 1;
    int n = AdjList[start].size();
    for(int i = 0; i < n; i++){
        if(!visited[AdjList[start][i]]){
            ans += DFS(AdjList, visited, AdjList[start][i]);   
        }
    }
    return ans;
}



int solution(vector<int> &A) {
    
    if(A.size() == 0){
        return 0;
    }
    int n = A.size();
    vector<int> AdjList[1000001];
    for(int i = 0; i < n ;i++){
        AdjList[i].push_back(A[i]);
        AdjList[A[i]].push_back(i);
    }
    int visited[1000001] = {0};
    int maxans = 0;
    for(int i = 0; i < n;  i++){
        if(!visited[i]){
            int ans = DFS(AdjList, visited, i);
            maxans = max(maxans, ans);
        }
    }
    return maxans;
}
