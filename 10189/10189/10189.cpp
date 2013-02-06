/*
 Solution to problem 10189
	by: Wei Wei Huang
 Language: C++
*/
#include <iostream>
#include <string>
using namespace std;

int** createGrid(const int x, const int y){
	int** grid = new int* [x];

	//create and initialize grid to 0
	for(int i = 0; i < x; i++){
		grid[i] = new int[y];
		for(int j = 0; j < y; j++)
		{
			grid[i][j] = 0;
		}
	}
	return grid;
}

void incrementNeighbors(int** grid, int x, int y, int maxRow, int maxCol){
	if(x > 0){
		if(grid[x-1][y] != -1) grid[x-1][y]++;
		if(y > 0) {
			if(grid[x-1][y-1] != -1) grid[x-1][y-1]++;
		}
		if(y < maxCol-1) {
			if(grid[x-1][y+1] != -1) grid[x-1][y+1]++;
		}
	}
	if(x < maxRow-1){
		if(grid[x+1][y] != -1) grid[x+1][y]++;
		if(y > 0) {
			if(grid[x+1][y-1] != -1) grid[x+1][y-1]++;
		}
		if(y < maxCol-1) {
			if(grid[x+1][y+1] != -1) grid[x+1][y+1]++;
		}
	}
	if(y > 0){
		if(grid[x][y-1] != -1) grid[x][y-1]++;
	}
	if(y < maxCol-1){
		if(grid[x][y+1] != -1) grid[x][y+1]++;
	}
}

void printGrid(int** grid, int x, int y){
	for(int i = 0; i < x; i++)
	{
		for(int j = 0; j < y; j++){
			if(grid[i][j] == -1)
				cout << '*';
			else
				cout << grid[i][j];
		}
		if(i < x-1)
			cout << endl;
	}	
}

int main(){
	int x,y,field = 1, first = 0;
	while(cin >> x >> y){
		int** grid = createGrid(x,y);
		string row;
		//set all mines to -1 and increment neighbors
		if(x != 0 && y != 0){
			for(int rowAt = 0; rowAt < x; rowAt++){
				cin >> row;
				for(int i = 0; i < y; i++){
					if(row.at(i) == '*'){
						grid[rowAt][i] = -1;
						incrementNeighbors(grid, rowAt, i, x, y);
					}
				}
				if(rowAt+1 == x){
					if(first != 0) cout << endl << endl;
					cout << "Field #" << field << ":" << endl;
					printGrid(grid, x, y);					
					field++;
					break;
				}
			}
		}
		if(first == 0) 
			first = 1;
		for( int i = 0 ; i < x ; i++ )
			delete [] grid[i] ;
		delete [] grid;
	}

	return 0;
}