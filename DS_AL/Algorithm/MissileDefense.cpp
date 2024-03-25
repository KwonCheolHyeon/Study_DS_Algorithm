#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>>& targets) {
    // 시작점을 기준으로 오름차순 정렬
    sort(targets.begin(), targets.end());

    // 첫 번째 요격 미사일은 첫 번째 폭격 미사일의 끝점으로 설정
    int interception_missile = targets[0][1];
    // 요격 미사일의 개수
    int missile_count = 1;

    // 각 폭격 미사일을 돌면서
    for (int i = 1; i < targets.size(); ++i) {
        // 현재 요격 미사일이 관통할 수 있는 범위를 넘어서면
        if (targets[i][0] > interception_missile) {
            // 새로운 요격 미사일이 필요하므로 개수 증가
            missile_count++;
            // 새로운 요격 미사일의 범위 설정
            interception_missile = targets[i][1];
        }
        else {
            // 현재 요격 미사일이 관통할 수 있는 범위를 업데이트
            interception_missile = min(interception_missile, targets[i][1]);
        }
    }

    return missile_count;
}
