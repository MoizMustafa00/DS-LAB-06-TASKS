#include<iostream>
using namespace std;

void dispSequence(int n) {
	if(n <= -1) {
		return;
	}
	dispSequence(n-1);
	cout << n << " ";
}

int main() {
	int n = 5;
	dispSequence(n);
	return 0;
}
