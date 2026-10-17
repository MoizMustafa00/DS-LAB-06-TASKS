#include<iostream>
using namespace std;

int sumOfDigits(int n) {
	if(n == 0) {
		return 0;
	}
	int sum = n % 10;
	return sum + sumOfDigits(n/10);
}

int main() {
	int n = 345;
	cout << sumOfDigits(n);
	return 0;
}
