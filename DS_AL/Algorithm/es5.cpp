#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>


using namespace std;


int solution5(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    int fatigue = k;
    int answerCount = 0;
    do {
        fatigue = k;
        answerCount = 0;
        for (int i = 0; i < dungeons.size(); i++)
        {
            if (fatigue >= dungeons[i][0])
            {
                fatigue = fatigue - dungeons[i][1];
                answerCount++;
            }
        }
        answer = max(answer, answerCount);

    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}
