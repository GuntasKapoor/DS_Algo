#include <bits/stdc++.h>
using namespace std;
void transitiveClosure(int matrix[100][100],int N,int src){
    queue<int> q;
    q.push(src);
    map<int,bool> visited;
    visited[src]=true;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int i=0;i<N;i++){
            if(matrix[top][i]!=0 && visited[i]!=true){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(visited[i]!=true){
            cout<<'0'<<" ";
        }
        else{
            cout<<'1'<<" ";
        }
    }
}

int main() {
    int matrix[100][100];
    int N;
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>matrix[i][j];
            }
        }
        for(int i=0;i<N;i++){
            transitiveClosure(matrix,N,i);
        }
    }
	return 0;
}