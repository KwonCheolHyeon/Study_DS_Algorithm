#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void dfsbfs01(vector<int>& numbers, int target, int sum, int idx) {
    if (idx == numbers.size()) {
        cout << sum << endl;
        if (sum == target) {
            answer++;
        }
        return;
    }

    dfsbfs01(numbers, target, sum + numbers[idx], idx + 1);
    dfsbfs01(numbers, target, sum - numbers[idx], idx + 1);
}

int solutiondfs1(vector<int> numbers, int target) {
    dfsbfs01(numbers, target, 0, 0);
    return answer;
}



int main() {
    vector<int> numbers1 = { 1, 1, 1, 1, 1 };
    int target1 = 3;
    int result1 = solutiondfs1(numbers1, target1);
    cout << result1 << endl; // 출력값: 5

    //vector<int> numbers2 = { 4, 1, 2, 1 };
    //int target2 = 4;
    //int result2 = solutiondfs1(numbers2, target2);
    //cout << result2 << endl; // 출력값: 2

    return 0;
}
