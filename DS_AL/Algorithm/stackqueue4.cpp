#include<string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int solutionsq4(vector<int> priorities, int location) 
{
    queue<pair<int, int>> q; //Æä¾î
    for (int i = 0; i < priorities.size(); ++i) 
    {
        q.push({ priorities[i], i }); 
    }

    int execution_order = 0; 

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        bool hasHigherPriority = false;

        for (queue<pair<int, int>> tempQ = q; !tempQ.empty(); tempQ.pop()) 
        {
            if (tempQ.front().first > current.first)
            {
                hasHigherPriority = true;
                break;
            }
        }

        if (hasHigherPriority)
        {
            q.push(current);

        }
        else 
        {
            execution_order++;
            if (current.second == location) {

                return execution_order;
            }
        }
    }
}
