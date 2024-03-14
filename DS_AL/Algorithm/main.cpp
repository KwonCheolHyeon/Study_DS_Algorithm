#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution4(int brown, int yellow)
{
    vector<int> answer;

    int hap = brown + yellow;
    int a = sqrt(hap);
    int b = 1;
    while (true)
    {
        if ((a * b) == hap)
        {
            break;
        }
        b++;
    }
    if (a < b) 
    {
        answer.push_back(b);
        answer.push_back(a);
    }
    else 
    {
        answer.push_back(a);
        answer.push_back(b);
    }
   

    return answer;
}

int main()
{

   cout << solution4(24, 24)[0] << solution4(24, 24)[1];

}