#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs2(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start); // 시작 노드를 큐에 넣음
    visited[start] = true; // 시작 노드를 방문했다고 표시

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Visited node: " << node << endl;

        // 현재 노드의 인접한 모든 노드를 방문
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
        {1, 2},     // 노드 0과 연결된 노드들
        {0, 3, 4},  // 노드 1과 연결된 노드들
        {0, 5},     // 노드 2과 연결된 노드들
        {1},        // 노드 3과 연결된 노드들
        {1},        // 노드 4과 연결된 노드들
        {2}         // 노드 5과 연결된 노드들
    };

    // 노드의 방문 여부를 나타내는 배열
    vector<bool> visited(graph.size(), false);

    // BFS 탐색 시작 (노드 0에서부터 시작)
    bfs2(0, graph, visited);

    return 0;
}
