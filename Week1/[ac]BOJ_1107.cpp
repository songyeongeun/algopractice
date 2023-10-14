#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int my = 100; // 초기값
    int target;   // 타겟
    int n;        // 고장난 버튼 개수

    cin >> target >> n;

    // 입력받은 고장난 버튼 정보 저장
    vector<char> brok_bttn(n);
    vector<char> use_bttn(10, 1); // 모든 버튼 사용 가능으로 초기화

    // 고장난 버튼 정보 반영
    for (int i = 0; i < n; i++)
    {
        cin >> brok_bttn[i];
        use_bttn[brok_bttn[i] - '0'] = 0; // 고장난 버튼을 표시. '0'을 빼서 int로
    }

    int count1 = abs(target - my); // +나 -만으로 target까지 가는 횟수

    int count2; // 모든 버튼 조합 돌려서 가장 작은 클릭 횟수 저장하는 변수

    if (my == target) // target이 100인 경우
    {
        cout << "0" << endl;
        return 0;
    }

    string target_str = to_string(target); // 문자로 비교하기 위해서 숫자를 문자열로 바꿈
    count2 = abs(target - 100);            // +나 -만으로 target까지 가는 횟수로 초기화.

    for (int i = 0; i <= 5000000; i++) // 모든 숫자들을 다 돌림
    {
        string cur = to_string(i); // 현재 반복 중인 숫자를 나태내기 위해

        bool possible = true; // 누르는 거 가능한지 체크
        for (char c : cur)    // cur에 '0'~'500000' 돌면서 가장 작은 수 찾기
        {
            if (!use_bttn[c - '0']) // 사용 가능한 버튼이 아니면 break
            {
                possible = false;
                break;
            }
        }

        if (possible) // 사용 가능한 버튼이면
        {
            count2 = min(count2, abs(target - i) + static_cast<int>(cur.length())); // cur.length()는 size니까 int로 형변환
        }                                                                           //(+나 -만으로 이동하는 횟수)와 (타겟 - 누를 수 있는 버튼 조합 + 누를 수 있는 조합의 길이) 중 더 작은 값을 count2로
    }

    cout << count2 << endl; // 최소값인 count2 출력

    return 0;
}
