#include<iostream>
using namespace std;

const int R = 4, C = 4;
char grid[R][C] = {{'C', 'A', 'R', 'T'},
				   {'X', 'T', 'A', 'B'},
				   {'B', 'O', 'C', 'D'},
				   {'E', 'F', 'G', 'H'}};
bool visited[R][C] = {false};
const char* word = "CAT";
const int LEN = 3;

bool search(int row, int col, int idx) {
	if(row < 0 || row >= R || col < 0 || col >= C) {
		return false;
	}
	if(visited[row][col] || grid[row][col] != word[idx]) {
		return false;
	}
	if(idx == LEN - 1) {
		return true;
	}

	visited[row][col] = true;
	bool found = search(row, col + 1, idx + 1) ||
				 search(row + 1, col, idx + 1) ||
				 search(row, col - 1, idx + 1) ||
				 search(row - 1, col, idx + 1);
	visited[row][col] = false;
	return found;
}

int main() {
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			if(search(i, j, 0)) {
				cout << "Word \"" << word << "\" found!" << endl;
				return 0;
			}
		}
	}
	cout << "Word \"" << word << "\" not found." << endl;
	return 0;
}
