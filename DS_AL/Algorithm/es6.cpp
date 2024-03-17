#include <vector>
#include <algorithm>

using namespace std;

int dfs2(int node, const vector<vector<int>>& graph, vector<bool>& visited) 
{
    visited[node] = true;
    int count = 1; // ���� ��带 �����ϹǷ� 1���� ����
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            count += dfs2(neighbor, graph, visited);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    // ���¸� �׷��� ����
    vector<vector<int>> graph(n + 1); // 1���� �����ϱ� ���� n + 1 ũ���� ���� ����
    for (const auto& wire : wires) {
        graph[wire[0]].push_back(wire[1]);
        graph[wire[1]].push_back(wire[0]);
    }

    // ���� �ϳ��� ����鼭 �� ���� �׷����� ����ž ���� ���� ���
    int min_difference = n;
    for (const auto& wire : wires) {
        vector<bool> visited(n + 1, false);
        visited[wire[0]] = visited[wire[1]] = true; // ������ ������ �� �� ���� �׷����� �ǹǷ� �� ����ž�� �湮 ó��
        int count1 = dfs2(wire[0], graph, visited); // ù ��° ���� �׷����� ����ž ����
        int count2 = n - count1; // �� ��° ���� �׷����� ����ž ����
        min_difference = min(min_difference, abs(count1 - count2));
    }

    return min_difference;
}
