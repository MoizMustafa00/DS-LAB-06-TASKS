#include<iostream>
using namespace std;

const int N = 4;
int maze[N][N] = {{1, 0, 0, 0},
				  {1, 1, 0, 1},
				  {0, 1, 0, 0},
				  {1, 1, 1, 1}};
				  
int path[N][N] = {0};

bool isSafe(int row, int col) {
	if(row < 0 || row >= N || col < 0 || col >= N) {
		return false;
	}
	
	if(maze[row][col] == 0) {
		return false;
	}
	return true;
}

bool findPath(int row, int col) {
	if(!isSafe(row, col)) {
        return false;
    }
    path[row][col] = 1;
    
    if(row == N-1 && col == N-1) {
        return true;
    }
	
	if(findPath(row, col+1)) {
		return true;
	}
	if(findPath(row+1, col)){
		return true;
	}
	path[row][col] = 0;
	return false;
}

void printPath() {
	cout << "Path:\n\n";
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cout << path[i][j] << " "; 
		}
		cout << endl;
	}
}

int main() {
	cout << "Maze:\n\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	if (findPath(0, 0)) {
		cout << "Path found!\n\n";
		printPath();
	}
	else {
		cout << "No path exists.\n";
	}
	return 0;
}
