#include <vector>
#include <cmath>

using namespace std;

vector<int> solutiones4(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    // 카펫의 가로 길이를 1부터 시작하여 적절한 가로 길이를 찾습니다.
    for (int width = 1; width <= sqrt(total); ++width) {
        // 가로 길이로 전체 넓이를 나눌 수 있는 경우에만 확인합니다.
        if (total % width == 0) {
            int height = total / width;
            // 주어진 yellow와 일치하는지 확인합니다.
            if ((width - 2) * (height - 2) == yellow) {
                // 가로와 세로를 오름차순으로 정렬하여 answer에 추가합니다.
                answer.push_back(height);
                answer.push_back(width);
                break;
            }
        }
    }
    return answer;
}
