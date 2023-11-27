#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int a[1000][1000];
    
    int x = 0, y = 0;
    int dir_flag = 0;
    int num = 1;
    
    for(int i=0; i<n; i++) {
        if (dir_flag == 0) {
            for(int k=i; k<n; k++) {
                a[x++][y] = num++;
            }
            x--;
            y++;
            dir_flag = 1;
        }
        else if (dir_flag == 1) {
            for(int k=i; k<n; k++) {
                a[x][y++] = num++;
            }
            x--;
            y-=2;
            dir_flag = 2;
        }
        else if (dir_flag == 2) {
            for(int k=i; k<n; k++) {
                a[x--][y--] = num++;
            }
            x+=2;
            y++;
            dir_flag = 0;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            answer.push_back(a[i][j]);
        }
    }
    
    return answer;
}
