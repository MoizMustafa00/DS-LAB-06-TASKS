#include<iostream>
using namespace std;

const int N = 5;
int numbers[N] = {2, 3, 5, 6, 8};
const int TARGET = 9;

bool chosen[N] = {false};

bool findSubset(int index, int currentSum) {
	if(currentSum == TARGET) {
		return true;
	}
	if(index == N || currentSum > TARGET) {
		return false;
	}

	chosen[index] = true;
	if(findSubset(index + 1, currentSum + numbers[index])) {
		return true;
	}

	chosen[index] = false;
	return findSubset(index + 1, currentSum);
}

int main() {
	if(findSubset(0, 0)) {
		cout << "Subset: { ";
		for(int i = 0; i < N; i++) {
			if(chosen[i]) {
				cout << numbers[i] << " ";
			}
		}
		cout << "}" << endl;
	}
	else {
		cout << "No subset with sum = " << TARGET << " exists." << endl;
	}
	return 0;
}
