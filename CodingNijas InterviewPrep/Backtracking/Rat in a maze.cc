// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

bool isPath(int **input,int **visited, int x,int y,int m,int n){
	if(x == m-1 && y == n-1){
		return true;
	}

	if(x<0 || y<0 || x>=m || y>=n || input[x][y]==0 ||visited[x][y]==1){
		return false;
	}

	// if all conditions are not satisfied above then we can include this node in path
	visited[x][y]=1;

	// Check further in all directions;
	if(isPath(input,visited,x-1,y,m,n)){
		return true;
	}
	if(isPath(input,visited,x+1,y,m,n)){
		return true;
	}
	if(isPath(input,visited,x,y-1,m,n)){
		return true;
	}
	if(isPath(input	,visited,x,y+1,m,n)){
		return true;
	}
	// if no path is there further then set the current block to 0 to not to include it in the path
	visited[x][y]=0;
	return false;
}

void Printallpaths(int **input,int **visited, int x,int y,int m,int n){
if(x == m-1 && y == n-1){
		visited[x][y]=1;
		for(int i = 0 ; i < m; i++){
			for(int j = 0; j < n; j++){
				cout<<visited[i][jo]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}

	if(x<0 || y<0 || x>=m || y>=n || input[x][y]==0 ||visited[x][y]==1){
		return;
	}

	// if all conditions are not satisfied above then we can include this node in path
	visited[x][y]=1;

	// Check further in all directions;
	Printallpaths(input,visited,x-1,y,m,n);
	Printallpaths(input,visited,x+1,y,m,n);o
	Printallpaths(input,visited,x,y-1,m,n);
	Printallpaths(input,visited,x,y+1,m,n);

	// if no path is there further then set the current block to 0 to not to include it in the path
	visited[x][y]=0;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int m,n;
cin>>m>>n;
int **input = new int*[m];
int **visited = new int*[m];
for(int i = 0 ; i < m; i++){
	input[i] = new int[n];
	visited[i] = new int[n];
	for(int j = 0; j < n ; j++){
		cin>>input[i][j];
		visited[i][j]=0;
	}
}
// if(isPath(input,visited,0,0,m,n)){
// 	cout<<"true"<<endl;
// }
// else{
// 	cout<<"false"<<endl;
// }

Printallpaths(input,visited,0,0,m,n);
}