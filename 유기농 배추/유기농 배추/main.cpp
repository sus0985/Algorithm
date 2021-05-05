#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool v[51][51];
bool check[51][51];
void dfs(int x, int y, int M, int N, int K) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (v[nx][ny] && !check[nx][ny]) {
			check[nx][ny] = true;
			dfs(nx, ny, M, N, K);
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int T;
	cin >> T;

	while (T--) {
		int count = 0;
		int M, N, K;
		cin >> M >> N >> K;

		memset(v, false, sizeof(v));
		memset(check, false, sizeof(check));
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			v[x][y] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!check[i][j] && v[i][j]) {
					count++;
					check[i][j] = true;
					dfs(i, j, M, N, K);
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}