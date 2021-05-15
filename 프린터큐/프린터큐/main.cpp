#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int max_ele(deque<pair<int, int>>& dq) {
	int max = 0;
	for (int i = 0; i < dq.size(); i++) {
		if (max < dq[i].first)
			max = dq[i].first;
	}

	return max;
}

int main() {
	int T;

	cin >> T;

	while (T--) {
		int n, target, count = 0;
		cin >> n >> target;
		deque<pair<int, int>> dq;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			dq.push_back(make_pair(temp, i));
		}

		while (true) {
			int max = max_ele(dq);
			pair<int, int> p = dq.front();
			if (dq[0].first < max) {
				dq.pop_front(); dq.push_back(p);
				continue;
			}
			else {
				count++;
				dq.pop_front();
				if (p.second == target) {
					break;
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}