#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    // 이동할 네 방향 정의 (상, 하, 좌, 우)
    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };

    // BFS를 위한 큐 초기화
    queue<pair<int, int>> q;
    q.push({ 0, 0 });  // 시작 지점
    vector<vector<int>> distance(n, vector<int>(m, -1));  // 시작 지점으로부터의 거리를 저장할 배열 초기화
    distance[0][0] = 1;  // 시작 지점 거리는 1

    // BFS 수행
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 네 방향으로의 이동을 확인
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 이동한 위치가 맵 안에 있고, 벽이 아니며, 아직 방문하지 않았다면
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    // 상대 팀 진영까지의 최단 거리 반환
    return distance[n - 1][m - 1];
}

int main() {
    vector<vector<int>> maps = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1}
    };
    cout << solution(maps) << endl;  // Output: 11

    return 0;
}