/////////////////////////
// 2022.09.04 / kkarung /
//     brute force     //
/////////////////////////
///////////////////////////////// report ///////////////////////////////////////
// 가장 왼쪽 위 칸을 origin으로 두고, 그 오른쪽 8칸, 아래 8칸, 총 64칸 중에서 색칠해야 할 칸 세고
// (= countPainted 함수)
// origin을 아래로 (m-8)번, 오른쪽으로 (n-7)번 움직여서 위 과정을 반복한다
// (= main의 이중 for문)
// 이 때의 시간 복잡도는 log(n^3)이지만 최대 63x(m-8)x(n-8), 약 10의 5승이므로 괜찮음
// countPainted 함수에서 origin과 같은 색이어야 하는지는 2로 나눈 값을 flag로 생각하여 확인
// 예를 들어 origin: (0, 0), W, flag:0 이면, (1, 0)은 flag:1이므로 B여야함
// 다만, 64칸 중 과반수 이상을 색칠해야 한다면, 원하는 목표 체스판과 반대로 칠한다고 생각하면
// (64-과반수)번 색칠하면 되므로 색칠 횟수는 최대 32번임
// 이 예시가 예제 4
/*9 23
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBW*/

#include <iostream>
#define MAX 50
#define MAX_PAINT 63
using namespace std;

int countPainted(int, int, string[]);

int main() {
    int m, n;
    string input[MAX];
    int output = MAX_PAINT;

    cin >> m >> n;
    
    for (int i=0; i<m; i++) 
        cin >> input[i];
    
    for (int i=0; i<m-7; i++)
        for (int j=0; j<n-7; j++)
            output = min(countPainted(i, j, input), output);

    cout << output << '\n';
}

int countPainted (int y, int x, string input[]) {
    char origin = input[y][x];
    int origin_flag = (x+y==0 ? 0 : (x+y)%2);
    int retn = 0;
    //cout << origin << "\t" << origin_flag << "\n";
    for (int i=y; i<y+8; i++) {
        for (int j=x; j<x+8; j++){
            if (i==y&&j==x)
                continue;
            else {
                if ((origin_flag != (i+j)%2) && (origin == input[i][j]))
                // origin과 반대 색이 나와야 할 경우에 같은 색이 나오면
                    retn++;
                else if ((origin_flag == (i+j)%2) && (origin != input[i][j]))
                // origin과 동일 색이 나와야 할 경우에 다른 색이 나오면
                    retn++;
            }
        }
    }

    retn = (retn > 32) ? 64-retn : retn;

    return retn;
}
