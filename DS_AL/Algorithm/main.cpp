#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int solution6(int n, vector<vector<int>> wires) {
    int answer = -1;

    sort(wires.begin(), wires.end());

    do {
        for (int i = 0; i < wires.size(); i++)
        {
           
        }
    } while (next_permutation(wires.begin(), wires.end()));


    return answer;
}

int main()
{
    vector<vector<int>> wires = { {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} };
    cout << solution6(9, wires);

}