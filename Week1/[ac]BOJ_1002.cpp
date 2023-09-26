#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; // 테스트 케이스 개수
    cin >> t;
    double a, b, d;

    int x_1, y_1, x_2, y_2, r_1, r_2;

    for (int i = 0; i < t; i++) // 테스트케이스 수만큼 반복
    {
        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;   // x1,y1,r1, x2,y2,r2 입력
        d = sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2)); // 중점 사이 거리

        a = fabs(r_2 - r_1); // 반지름 사이 거리 -> 절댓값(혹시나 음수 나오면 어쩌나~)
        b = fabs(r_2 + r_1);

        if (a < d && d < b) // 두 점에서 만나는 경우
        {
            cout << "2\n";
        }
        else if (a == 0 && d == 0)
        { // 두 원이 일치해서 무한대
            cout << "-1\n";
        }
        else if (b == d || a == d) // 한 점에서 만나는 경우
        {
            cout << "1\n";
        }
        else if (b < d || d < a || (d == 0 && r_1 != r_2)) // 만나지 않는 경우
            cout << "0\n";
    }

    return 0;
}