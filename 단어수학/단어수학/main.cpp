#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char alpha[256];

int calc(vector<string>& v, vector<char>& c, vector<int>& d) {
	int m = c.size();
	int sum = 0;
	for (int i = 0; i < m; i++) {
		alpha[c[i]] = d[i];
	}

	for (string s : v) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + alpha[x];
		}
		sum += now;
	}
	return sum;
}

int main() {
	int M;

	cin >> M;

	vector<string> v(M);
	vector<char> c;
	for (int i = 0; i < M; i++) {
		cin >> v[i];
		for (int j = 0; j < v[i].size(); j++) {
			c.push_back(v[i][j]);
		}
	}

	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	int m = c.size();

	vector<int> d(m);

	for (int i = 9; i > 9 - m; i--) {
		d.push_back(i);
	}

	sort(d.begin(), d.end());
	
	int ans = 0;

	do {
		int now = calc(v, c, d);
		if (ans < now)
			ans = now;
	} while (next_permutation(d.begin(), d.end()));

	cout << ans << endl;


	return 0;
}