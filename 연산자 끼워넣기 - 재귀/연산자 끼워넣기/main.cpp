#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> go(vector<int>& v, int index, int cur, int plus, int minus, int mul, int div) {
	if (index == v.size())
		return make_pair(cur, cur);

	vector<pair<int, int>> res;
	if (plus > 0)
		res.push_back(go(v, index + 1, cur + v[index], plus - 1, minus, mul, div));
	if (minus > 0)
		res.push_back(go(v, index + 1, cur - v[index], plus, minus - 1, mul, div));
	if (mul > 0)
		res.push_back(go(v, index + 1, cur * v[index], plus, minus, mul - 1, div));
	if (div > 0)
		res.push_back(go(v, index + 1, cur / v[index], plus, minus, mul, div - 1));

	auto ans = res[0];
	for (auto p : res) {
		if (ans.first < p.first)
			ans.first = p.first;
		if (ans.second > p.second)
			ans.second = p.second;
	}

	return ans;
}


int main() {
	int n;

	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int plus, minus, mul, div;

	cin >> plus >> minus >> mul >> div;

	auto ans = go(v, 1, v[0], plus, minus, mul, div);

	cout << ans.first << endl << ans.second;


	return 0;
}