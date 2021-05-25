#include <iostream>
#include <string>
using namespace std;

int main() {
	char num[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int a, b, c;
	cin >> a >> b >> c;

	int res = a * b * c;

	string str = to_string(res);

	for (int i = 0; i < 10; i++) {
		int count = 0;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == num[i])
				count++;
		}

		cout << count << endl;
	}

	return 0;
}