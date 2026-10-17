#include<iostream>
using namespace std;

const int N = 4;
char chars[N] = {'A', 'B', 'C', 'D'};
char current[N];
bool used[N] = {false};
int count = 0;

void permute(int pos) {
	if(pos == N) {
		count++;
		for(int i = 0; i < N; i++) {
			cout << current[i];
		}
		cout << endl;
		return;
	}
	for(int i = 0; i < N; i++) {
		if(!used[i]) {
			used[i] = true;
			current[pos] = chars[i];
			permute(pos + 1);
			used[i] = false;
		}
	}
}

int main() {
	permute(0);
	cout << "Total: " << count << endl;
	return 0;
}
