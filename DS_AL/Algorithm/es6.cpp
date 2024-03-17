#include <vector>
#include <algorithm>

using namespace std;

int dfs2(int node, const vector<vector<int>>& graph, vector<bool>& visited) 
{
    visited[node] = true;
    int count = 1; // 현재 노드를 포함하므로 1부터 시작
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            count += dfs2(neighbor, graph, visited);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    // 전력망 그래프 구성
    vector<vector<int>> graph(n + 1); // 1부터 시작하기 위해 n + 1 크기의 벡터 생성
    for (const auto& wire : wires) {
        graph[wire[0]].push_back(wire[1]);
        graph[wire[1]].push_back(wire[0]);
    }

    // 전선 하나씩 끊어보면서 두 서브 그래프의 송전탑 개수 차이 계산
    int min_difference = n;
    for (const auto& wire : wires) {
        vector<bool> visited(n + 1, false);
        visited[wire[0]] = visited[wire[1]] = true; // 전선을 끊었을 때 두 서브 그래프가 되므로 두 송전탑을 방문 처리
        int count1 = dfs2(wire[0], graph, visited); // 첫 번째 서브 그래프의 송전탑 개수
        int count2 = n - count1; // 두 번째 서브 그래프의 송전탑 개수
        min_difference = min(min_difference, abs(count1 - count2));
    }

    return min_difference;
}
