// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

bool isSafe(int grid[][9], int i,int j,int a){
	for(int row = 0 ; row <9 ; row++){
			if(grid[row][j]==a){
				return false;
			}
		}
		// check in col
		for(int col = 0 ; col <9 ; col++){
			if(grid[i][col]==a){
				return false;
			}
		}
		// check in box
		int startrow = i-i%3;
		int startcol = j-j%3;
		for(int row = startrow; row < startrow + 3;row++){
			for(int col = startcol; col < startcol + 3; col++){
				if(grid[row][col]==a){
					return false;				
			    }
			}
			}
			return true;
}
bool SudokuSolver(int grid[][9], int i, int j){

	if(i==8 && j==9){
		for(int i = 0 ; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	if(j == 9){
		return SudokuSolver(grid, i+1, 0);
	}
	if(grid[i][j]!=0){
		return SudokuSolver(grid, i, j+1);
	}

	for(int a = 1; a<=9 ; a++){
		// Check in row
		
		if(isSafe(grid,i,j,a)){
			grid[i][j] = a;
			bool check = SudokuSolver(grid, i, j+1);
			if(check){
				return true;
			}
			else{
				grid[i][j]=0;
			}
		}
	}
		return false;
}








int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int grid[9][9]=      {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 
cout<<SudokuSolver(grid,0,0);

}