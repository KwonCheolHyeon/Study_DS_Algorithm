#include <vector>
#include <queue>

using namespace std;

int solutiondfs3(vector<vector<int>> maps) {
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // 방향: 상, 하, 좌, 우
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) {
            answer = visited[x][y];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && visited[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }

    if (answer == 0) {
        answer = -1; // 도달할 수 없는 경우
    }

    return answer;
}
