#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    // 현재 노드를 방문했다고 표시
    visited[node] = true;
    cout << "Visited node: " << node << endl;

    // 현재 노드와 연결된 모든 미방문 노드를 재귀적으로 탐색
    for (int neighbor : graph[node]) 
    {
        if (!visited[neighbor]) 
        {
            dfs(neighbor, graph, visited);
        }
    }
}

int main2() 
{
    vector<vector<int>> graph = 
    {
        {1, 2},     // 노드 0과 연결된 노드들
        {0, 3, 4},  // 노드 1과 연결된 노드들
        {0, 5},     // 노드 2과 연결된 노드들
        {1},        // 노드 3과 연결된 노드들
        {1},        // 노드 4과 연결된 노드들
        {2}         // 노드 5과 연결된 노드들
    };

    vector<bool> visited(graph.size(), false);

    dfs(0, graph, visited);

    return 0;
}