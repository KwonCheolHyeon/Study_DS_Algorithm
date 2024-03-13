#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

map<int, bool> MAP;

bool isPrime(string num) {
    int n = stoi(num);

    if (MAP[n]) return false; // 이미 확인한 수라면 중복이기 때문에 false 리턴
    MAP[n] = true;
    if (n == 1 || n == 0) return false;
    if (n == 2) return true;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            MAP[n] == -1;
            return false;
        }
    }
    MAP[n] == 1;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    // 오름차순 정렬
    sort(numbers.begin(), numbers.end());//next_permutation함수가 오름차순에서만 쓰인다 
    // 나올 수 있는 모든 조합에 대해서
    // 한 자리수인 경우, 두 자리수인 경우, ..., numbers.size() 자리수인 경우
    // 를 모두 검사
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            string num = numbers.substr(0, i);
            if (isPrime(num)) answer++;
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return answer;
}