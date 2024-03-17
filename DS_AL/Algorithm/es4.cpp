#include <vector>
#include <cmath>

using namespace std;

vector<int> solutiones4(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    // ī���� ���� ���̸� 1���� �����Ͽ� ������ ���� ���̸� ã���ϴ�.
    for (int width = 1; width <= sqrt(total); ++width) {
        // ���� ���̷� ��ü ���̸� ���� �� �ִ� ��쿡�� Ȯ���մϴ�.
        if (total % width == 0) {
            int height = total / width;
            // �־��� yellow�� ��ġ�ϴ��� Ȯ���մϴ�.
            if ((width - 2) * (height - 2) == yellow) {
                // ���ο� ���θ� ������������ �����Ͽ� answer�� �߰��մϴ�.
                answer.push_back(height);
                answer.push_back(width);
                break;
            }
        }
    }
    return answer;
}
