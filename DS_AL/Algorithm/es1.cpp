#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int height = 0; // 높이
    int width = 0; // 가로

    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] > sizes[i][1])
        {
            height = max(height, sizes[i][0]);
            width = max(width, sizes[i][1]);
        }
        else
        {
            height = max(height, sizes[i][1]);
            width = max(width, sizes[i][0]);
        }

    }


    return height * width;
}