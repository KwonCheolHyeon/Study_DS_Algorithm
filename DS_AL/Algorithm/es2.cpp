#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solutiones2(vector<int> answers) {
    vector<int> pattern1 = { 1, 2, 3, 4, 5 };
    vector<int> pattern2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> pattern3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    vector<int> scores(3, 0); // �� �����ڵ��� ������ �����ϴ� �迭

    // �� �����ڵ��� ���� ���
    for (int i = 0; i < answers.size(); ++i) {
        if (answers[i] == pattern1[i % pattern1.size()]) scores[0]++;
        if (answers[i] == pattern2[i % pattern2.size()]) scores[1]++;
        if (answers[i] == pattern3[i % pattern3.size()]) scores[2]++;
    }

    // ���� ���� ������ ���� ���� ���
    int max_score = *max_element(scores.begin(), scores.end());

    // ���� ���� ������ ���� �����ڵ��� ã�Ƽ� ����� �߰�
    vector<int> result;
    for (int i = 0; i < 3; ++i) {
        if (scores[i] == max_score) {
            result.push_back(i + 1); // ������ ��ȣ�� 1���� �����ϹǷ� 1�� ������
        }
    }

    return result;
}
