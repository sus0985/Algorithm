#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(vector<int>& d, vector<int>& temp) {
	int size = temp.size();
	int sum = d[0];

	for (int i = 0; i < size; i++) {
		switch (temp[i]) {
		case 0:
			sum += d[i + 1];
			break;
		case 1:
			sum -= d[i + 1];
			break;
		case 2:
			sum *= d[i + 1];
			break;
		case 3:
			sum /= d[i + 1];
			break;
		}
	}

	return sum;
}

int main() {
	int N;

	cin >> N;

	vector<int> d(N);

	for (int i = 0; i < N; i++) {
		cin >> d[i];
	}

	vector<int> r(4);

	for (int i = 0; i < 4; i++) {
		cin >> r[i];
	}

	vector<int> temp;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < r[i]; j++) {
			temp.push_back(i);
		}
	}

	//long min = 1e10;
	//long max = -1e10;
	//do {
	//	int now = calc(d, temp);
	//	if (max < now)
	//		max = now;
	//} while (next_permutation(temp.begin(), temp.end()));

	//do {
	//	int now = calc(d, temp);
	//	if (min > now)
	//		min = now;
	//} while (next_permutation(temp.begin(), temp.end()));

	
	/* 백준 풀이*/
	vector<int> result;

	do {
		result.push_back(calc(d, temp));
	} while (next_permutation(temp.begin(), temp.end()));

	auto ans = minmax_element(result.begin(), result.end());

	cout << *ans.second << endl << *ans.first;
	return 0;
}