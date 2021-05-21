#include <iostream>
using namespace std;

int num[20];

bool c[20 * 100000 + 10];	// �ִ밪

void go(int i,int sum, int n) {
	if (i == n) {
		c[sum] = true;
		return;
	}

	go(i + 1, sum + num[i], n);
	go(i + 1, sum, n);
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	go(0, 0, n);
	for (int i = 1; i < 20 * 100000 + 10; i++) {
		if (!c[i]) {
			cout << i;
			return 0;
		}
	}

	return 0;
}