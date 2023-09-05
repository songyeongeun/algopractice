#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        int a;
        cin >> a >> str;
        for (int j = 0; str[j]; j++)
        {
            for (int k = 0; k < a; k++)
            {
                cout << str[j];
            }
        }
        cout << endl;
    }

    return 0;
}