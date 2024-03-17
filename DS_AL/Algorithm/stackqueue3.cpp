#include<string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool solutionsq3(string s)
{
    bool answer = true;
    stack<char> strs;

    for (char& c : s) 
    {
        if (c == '(') 
        {
            strs.push(c);
        }
        else
        {
            if (strs.empty()) 
            {
                return false;
            }
            else 
            {
                strs.pop();
            }
        }
    }
    return strs.empty();//비어 있으면 트루
}