#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    long long int sum1 = 0;
    long long int sum2 = 0;
    long long int avg = 0;
    long long int count = 0;

    queue<long long int> q1;
    queue<long long int> q2;

    for (int i = 0; i < queue1.size(); i++)
    {
        sum1 = sum1 + queue1[i];
        q1.push(queue1[i]);
        sum2 = sum2 + queue2[i];
        q2.push(queue2[i]);
    }

    avg = (sum1 + sum2) / 2;

    while (1)
    {
        if (sum1 > avg)
        {
            long long int a = q1.front();
            // if (a == avg)
            // {
            //     count = count + q2.size() + 1;
            //     return count;
            //     break;
            // }
            if (a > avg)
            {
                count = -1;
                return count;
                break;
            }
            else
            {
                q1.pop();
                q2.push(a);
                count++;
                sum1 = sum1 - a;
                sum2 = sum2 + a;
            }
        }
        else if (sum2 > avg)
        {
            long long int b = q2.front();
            // if (b == avg)
            // {
            //     count = count + q1.size() + 1;
            //     return count;
            //     break;
            // }
            if (b > avg)
            {
                count = -1;
                return count;
                break;
            }
            else
            {
                q2.pop();
                q1.push(b);
                count++;
                sum1 = sum1 + b;
                sum2 = sum2 - b;
            }
        }

        if (sum1 == avg && sum2 == avg)
        {
            return count;
        }

        if (queue1.size() * 3 == count)
        {
            count = -1;
            return count;
            break;
        }
    }
}

void printVector(vector<int> a)
{
    cout << '[';
    for (int i = 0; i < a.size(); i++)
    {
        if (i == a.size() - 1)
            cout << a[i] << ']';
        else
            cout << a[i] << ", ";
    }
}

int main()
{
    int result;
    int enter;
    vector<int> q1;
    vector<int> q2;

    for (int testcase = 1; testcase <= 3; testcase++)
    {
        if (testcase == 1)
        {
            q1 = {3, 2, 7, 2};
            q2 = {4, 6, 5, 1};
            result = 2;
        }
        else if (testcase == 2)
        {
            q1 = {1, 2, 1, 2};
            q2 = {1, 10, 1, 2};
            result = 7;
        }
        else if (testcase == 3)
        {
            q1 = {1, 1};
            q2 = {1, 5};
            result = -1;
        }
        enter = solution(q1, q2);
        cout << "[ test " << testcase << " ]\n";
        cout << "   input  >  ";
        printVector(q1);
        cout << ", ";
        printVector(q2);
        cout << '\n';
        cout << "   mean  >  " << result << '\n';
        if (result == enter)
            cout << "result  >  success.\n\n";
        else
            cout << "result  >  run for success " << enter << "is mean " << result << "different.\n\n";
    }
}
