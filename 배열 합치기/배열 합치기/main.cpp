#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int a, b;

	cin >> a >> b;

	vector<int> v1(a);
	vector<int> v2(b);
	vector<int> v(a + b);
	for (int i = 0; i < a; i++) {
		cin >> v1[i];
	}

	for (int i = 0; i < b; i++) {
		cin >> v2[i];
	}

	int start1 = 0;
	int start2 = 0;
	int count = 0;
	while (true) {
		if (v1[start1] > v2[start2]) {
			v[count++] = v2[start2++];
		}
		else {
			v[count++] = v1[start1++];
		}
		if (start1 == a) {
			for (int i = count; i < a + b; i++) {
				v[i] = v2[start2++];
			}
			break;
		}
		if (start2 == b) {
			for (int i = count; i < a + b; i++) {
				v[i] = v1[start1++];
			}
			break;
		}
	}

	for (int i = 0; i < a + b; i++) {
		cout << v[i] << " ";
	}
	return 0;
}