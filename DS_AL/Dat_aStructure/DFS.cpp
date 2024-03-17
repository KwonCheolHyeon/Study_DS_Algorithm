#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    // ���� ��带 �湮�ߴٰ� ǥ��
    visited[node] = true;
    cout << "Visited node: " << node << endl;

    // ���� ���� ����� ��� �̹湮 ��带 ��������� Ž��
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
        {1, 2},     // ��� 0�� ����� ����
        {0, 3, 4},  // ��� 1�� ����� ����
        {0, 5},     // ��� 2�� ����� ����
        {1},        // ��� 3�� ����� ����
        {1},        // ��� 4�� ����� ����
        {2}         // ��� 5�� ����� ����
    };

    vector<bool> visited(graph.size(), false);

    dfs(0, graph, visited);

    return 0;
}