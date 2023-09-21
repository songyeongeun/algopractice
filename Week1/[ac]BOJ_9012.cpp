#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;

    for (int i = 0; i < n; i++)
    {
        stack<char> s;
        cin >> str;

        for (int i = 0; str[i]; i++)
        {
            if (str[i] == '(')
            {
                s.push('(');
            }
            else
            {
                if (s.empty() || s.top() == ')')
                    s.push(')');
                else if (s.top() == '(')
                {
                    s.pop();
                }
            }
        }
        if (s.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}