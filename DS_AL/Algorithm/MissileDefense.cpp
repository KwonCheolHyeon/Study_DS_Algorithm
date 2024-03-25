#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>>& targets) {
    // �������� �������� �������� ����
    sort(targets.begin(), targets.end());

    // ù ��° ��� �̻����� ù ��° ���� �̻����� �������� ����
    int interception_missile = targets[0][1];
    // ��� �̻����� ����
    int missile_count = 1;

    // �� ���� �̻����� ���鼭
    for (int i = 1; i < targets.size(); ++i) {
        // ���� ��� �̻����� ������ �� �ִ� ������ �Ѿ��
        if (targets[i][0] > interception_missile) {
            // ���ο� ��� �̻����� �ʿ��ϹǷ� ���� ����
            missile_count++;
            // ���ο� ��� �̻����� ���� ����
            interception_missile = targets[i][1];
        }
        else {
            // ���� ��� �̻����� ������ �� �ִ� ������ ������Ʈ
            interception_missile = min(interception_missile, targets[i][1]);
        }
    }

    return missile_count;
}
