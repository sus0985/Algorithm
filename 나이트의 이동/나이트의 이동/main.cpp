#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int chess[301][301] = { 0, };
int visited[301][301] = { 0, };

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main() {
	int T;

	cin >> T;

	while (T--) {
		int l;
		cin >> l;
		int sx, sy; cin >> sx >> sy;
		int ex, ey; cin >> ex >> ey;

		queue<pair<int, int>> q;

		q.push(make_pair(sx, sy));
		visited[sy][sx] = 1;
		chess[sy][sx] = 0;

		while (!q.empty()) {
			int x, y;
			pair<int, int> p = q.front(); q.pop();
			x = p.first; y = p.second;

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i]; int ny = y + dy[i];

				if (nx < l && ny < l && nx >= 0 && ny >= 0) {
					if (!visited[ny][nx]) {
						q.push(make_pair(nx, ny));
						visited[ny][nx] = 1;
						chess[ny][nx] = chess[y][x] + 1;
					}
				}
			}	
		}
		cout << chess[ey][ex] << endl;

		memset(chess, 0, sizeof(chess));
		memset(visited, 0, sizeof(visited));
	
	}

	return 0;
}