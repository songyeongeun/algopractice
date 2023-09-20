#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    string str;
    stack<char> s;

    while (n--)
    {

        getline(cin, str);
        // str += ' ';

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << ' ';
            }
            else
                s.push(str[i]);
        }
        cout << endl;
    }
}