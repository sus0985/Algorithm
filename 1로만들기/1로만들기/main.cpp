#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000000

int table[MAX + 1];

int main() {
	int n;

	cin >> n;

	table[1] = 0;
	table[2] = 1;
	table[3] = 1;

	for (int i = 4; i <= n; i++) {
		if (!table[i]) {
			if (i % 2 != 0 && i % 3 != 0) {
				table[i] = table[i - 1] + 1;
			}
			else if (i % 2 == 0 && i % 3 != 0) {
				table[i] = min(table[i / 2], table[i - 1]) + 1;
			}
			else if (i % 2 != 0 && i % 3 == 0) {
				table[i] = min(table[i / 3], table[i - 1]) + 1;
			}
			else {
				table[i] = min(min(table[i / 3], table[i / 2]), table[i - 1]) + 1;
			}
		}
	}

	cout << table[n];

	return 0;
}