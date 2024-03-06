#include <string>
#include <vector>

using namespace std;

vector<int> m1 = { 1,2,3,4,5 }; //4
vector<int> m2 = { 2,1,2,3,2,4,2,5 }; //7
vector<int> m3 = { 3,3,1,1,2,2,4,4,5,5 }; //9

vector<int> solution3(vector<int> answers) {
    vector<int> answer;
    int s[3] = { 0,0,0 };
    int max_score = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == m1[i % 5])
            s[0]++;
        if (answers[i] == m2[i % 8])
            s[1]++;
        if (answers[i] == m3[i % 10])
            s[2]++;
    }
    max_score = max(max(s[0], s[1]), s[2]);
    for (int i = 0; i < 3; i++)
    {
        if (max_score == s[i])
            answer.push_back(i + 1);
    }
    return answer;
}