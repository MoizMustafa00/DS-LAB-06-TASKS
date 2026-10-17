#include<iostream>
#include<string>
using namespace std;

bool isSafe(int v, int graph[4][4], int colors[], int c) {
	for(int i=0; i<4; i++) {
		if(graph[v][i] == 1 && colors[i] == c) {
			return false;
		}	
	}
	return true;
}

bool assignColors(int v, int graph[4][4], int colors[]) {
	if(v == 4) {
		return true;
	}
	for(int c=1; c<=3; c++) {
		if(isSafe(v, graph, colors, c)) {
			colors[v] = c;
			if(assignColors(v+1, graph, colors)) {
				return true;
			}
			colors[v] = 0;
		}
	}
	return false;
}

int main() {
	int graph[4][4] = { {0, 1, 1, 0},   //	  A B C D
					  {1, 0, 1, 1},		//	A 0 1 1 0
					  {1, 1, 0, 1},		//	B 1 0 1 1			
					  {0, 1, 1, 0} };	//	C 1 1 0 1			
										//	D 0 1 1 0
										
	string colorNames[] = {"Red", "Green", "Blue"};
    string vertexNames[] = {"A", "B", "C", "D"};
	int colors[4] = {0, 0, 0, 0};
	if (assignColors(0, graph, colors)) {
        for (int i = 0; i < 4; i++) {
            cout << vertexNames[i] << " = " << colorNames[colors[i] - 1] << endl;
        }
    } 
	else {
        cout << "No valid coloring exists" << endl;
    }
	return 0;
}
