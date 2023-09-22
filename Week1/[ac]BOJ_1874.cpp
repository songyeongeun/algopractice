#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num;
    int cnt = 1;

    vector<char> arr;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        while (s.empty() || s.top() < num)
        {
            s.push(cnt);
            arr.push_back('+');
            cnt++;
        }
        if (s.top() == num)
        {
            s.pop();
            arr.push_back('-');
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\n';
    }
}