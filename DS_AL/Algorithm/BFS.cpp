#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs2(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start); // ���� ��带 ť�� ����
    visited[start] = true; // ���� ��带 �湮�ߴٰ� ǥ��

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Visited node: " << node << endl;

        // ���� ����� ������ ��� ��带 �湮
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int RunBFS() {
    
    vector<vector<int>> graph = {
        {1, 2},     // ��� 0�� ����� ����
        {0, 3, 4},  // ��� 1�� ����� ����
        {0, 5},     // ��� 2�� ����� ����
        {1},        // ��� 3�� ����� ����
        {1},        // ��� 4�� ����� ����
        {2}         // ��� 5�� ����� ����
    };

    // ����� �湮 ���θ� ��Ÿ���� �迭
    vector<bool> visited(graph.size(), false);

    // BFS Ž�� ���� (��� 0�������� ����)
    bfs2(0, graph, visited);

    return 0;
}
