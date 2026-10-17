#include<iostream>
using namespace std;

const int N = 4;
int grid[N][N] = {{1, 0, 0, 4},
				  {0, 4, 1, 0},
				  {0, 1, 4, 0},
				  {4, 0, 0, 1}};

bool isSafe(int row, int col, int num) {
	for(int i = 0; i < N; i++) {
		if(grid[row][i] == num || grid[i][col] == num) {
			return false;
		}
	}
	int boxRow = (row / 2) * 2;
	int boxCol = (col / 2) * 2;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			if(grid[boxRow + i][boxCol + j] == num) {
				return false;
			}
		}
	}
	return true;
}

bool solve() {
	for(int row = 0; row < N; row++) {
		for(int col = 0; col < N; col++) {
			if(grid[row][col] == 0) {
				for(int num = 1; num <= N; num++) {
					if(isSafe(row, col, num)) {
						grid[row][col] = num;
						if(solve()) {
							return true;
						}
						grid[row][col] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}

int main() {
	if(solve()) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "No solution exists." << endl;
	}
	return 0;
}
