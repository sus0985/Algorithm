#include <iostream>
using namespace std;
int main() {
	int h, m;

	cin >> h >> m;

	if (m - 45 < 0) {
		h--;
		m = 60 - (-1*(m - 45));
		if (h < 0)
			h = 23;
	}
	else {
		m = m - 45;
	}

	cout << h << " " << m;
	return 0;
}