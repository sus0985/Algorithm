#include <iostream>
using namespace std;

int num[20];
bool c[20 * 100000 + 10];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))
				sum += num[j];
		}
		c[sum] = true;
	}

	for (int i = 1;;i++) {
		if (!c[i]) {
			cout << i;
			break;
		}
	}

	return 0;
}