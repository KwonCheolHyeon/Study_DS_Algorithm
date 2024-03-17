#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void dbfs1(vector<int>& numbers, int target, int sum, int idx) {
    if (idx == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }

    dbfs1(numbers, target, sum + numbers[idx], idx + 1);
    dbfs1(numbers, target, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    dbfs1(numbers, target, 0, 0);
    return answer;
}