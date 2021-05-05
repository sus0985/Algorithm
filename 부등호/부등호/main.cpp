#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool check(vector<int>& perm, vector<char>& v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == '<' && perm[i] > perm[i + 1])
			return false;
		if (v[i] == '>' && perm[i] < perm[i + 1])
			return false;
	}
	return true;
}
int main() {
	int k;

	cin >> k;

	vector<char> v(k);

	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}

	vector<int> small(k + 1);
	vector<int> big(k + 1);

	for (int i = 0; i <= k; i++) {
		small[i] = i;
		big[i] = 9 - i;
	}

	do {
		if (check(small, v))
			break;
	} while (next_permutation(small.begin(), small.end()));

	do {
		if (check(big, v))
			break;
	} while (prev_permutation(big.begin(), big.end()));

	for (int i = 0; i < big.size(); i++) {
		cout << big[i];
	}

	cout << endl;

	for (int i = 0; i < small.size(); i++) {
		cout << small[i];
	}

	return 0;
}


/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool calc(vector<char>& v, vector<int>& num) {
	int size = v.size();

	for (int i = 0; i < size; i++) {
		if (v[i] == '>' && num[i] < num[i + 1])
			return false;
		if (v[i] == '<' && num[i] > num[i + 1])
			return false;
	}

	return true;
	
}
int main() {
	int n;

	cin >> n;

	vector<char> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> num;

	for (int i = 9; i > 8 - n; i--) {
		num.push_back(i);
	}

	do {	
		if (calc(v, num)) {
			break;
		}
	} while (next_permutation(num.begin(), num.end()));

	reverse(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) {
		cout << num[i];
	}

	return 0;
}
*/