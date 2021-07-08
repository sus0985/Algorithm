#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

bool table[101][101];
int check[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;

		for (int j = 1; j <= m; j++) {
			if (str[j-1] == '1') {
				table[i][j] = true;
			}
		}
	}

	queue<pair<int, int>> q;

	q.push(make_pair(1, 1));
	check[1][1] = 1;

	while (!q.empty()) {
		int y, x;
		tie(x, y) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (table[nx][ny]) {
				if(nx >= 1 && ny >= 1 && nx <= n  && ny <= m)
					if (!check[nx][ny]) {
						check[nx][ny] = check[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
			}
		}
	}

	cout << check[n][m];

	return 0;
}
