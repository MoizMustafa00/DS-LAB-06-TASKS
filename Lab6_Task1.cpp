#include<iostream>
using namespace std;

void reverseString(string str, int n) {
	if(n == 0) {
		return;
	}
	cout << str[n-1];
	reverseString(str, n-1);
}

int main() {
	string str = "Moiz";
	int n = str.length();
	reverseString(str, n);
	return 0;
}
