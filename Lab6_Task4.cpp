#include<iostream>
using namespace std;

int doubleAmount(int day) {
	if(day == 1) {
		return 10;
	}
	return 2 * doubleAmount(day-1);
}

int main() {
	int n = 5;
	cout << doubleAmount(n);
	return 0;
}
