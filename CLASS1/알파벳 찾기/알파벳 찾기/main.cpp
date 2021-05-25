#include <iostream>
#include <string>
using namespace std;
/*int main() {
	int num[26] = { -1,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		int n = str[i] - 97;
		if (num[n] == -1) {
			num[n] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << num[i] << " ";
	}

	return 0;
}*/


int main() {
	string str;
	cin >> str;

	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < alphabet.size(); i++) {
		cout << (int)str.find(alphabet[i]) << " ";
	}

	return 0;
}