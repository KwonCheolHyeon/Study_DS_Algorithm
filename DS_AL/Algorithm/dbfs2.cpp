#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    // �̵��� �� ���� ���� (��, ��, ��, ��)
    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };

    // BFS�� ���� ť �ʱ�ȭ
    queue<pair<int, int>> q;
    q.push({ 0, 0 });  // ���� ����
    vector<vector<int>> distance(n, vector<int>(m, -1));  // ���� �������κ����� �Ÿ��� ������ �迭 �ʱ�ȭ
    distance[0][0] = 1;  // ���� ���� �Ÿ��� 1

    // BFS ����
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // �� ���������� �̵��� Ȯ��
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // �̵��� ��ġ�� �� �ȿ� �ְ�, ���� �ƴϸ�, ���� �湮���� �ʾҴٸ�
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    // ��� �� ���������� �ִ� �Ÿ� ��ȯ
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