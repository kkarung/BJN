/////////////////////////
// 2022.09.16/ kkarung //
//         DP          //
/////////////////////////
///////////////////////// report ///////////////////////////////
// DP[i][0]은 0번째 row, i번째 column에 위치한 스티커를 포함했을 때 최대 점수
// DP[i][1]은 1번째 row, i번째 column에 위치한 스티커를 포함했을 때 최대 점수
// 최댓값이 나오는 3가지 경우
// 1: (i-1,1) 스티커를 포함한 최대 점수 + (i,0)번째 스티커 점수
// 2: (i-1,0) 스티커를 포함한 최대 점수 + (i,1)번째 스티커 점수
// 3: i-2번째까지의 최대 점수 + max((i,0), (i,1))
// 주석은 내가 생각한 로직, 주석 아래 두 줄은 이를 간단히 한 것
// 9465_v1.cpp가 더 깔끔한 풀이

#include <iostream>
using namespace std;
#define MAXN 100000

int main() {
    int t, n;
    int sticker[MAXN][2] = {0};
    int DP[MAXN][2] = {0};

    cin >> t;

    while (t-->0) {
        cin >> n;

        for (int i=0; i<n; i++) cin >> sticker[i][0];
        for (int i=0; i<n; i++) cin >> sticker[i][1];

        DP[0][0] = sticker[0][0]; DP[0][1] = sticker[0][1];

        DP[1][0] = DP[0][1]+sticker[1][0]; DP[1][1] = DP[0][0]+sticker[1][1];

        for (int i=2; i<n; i++) {
            /*DP[i][0] = DP[i-1][1]+sticker[i][0];
            DP[i][1] = DP[i-1][0]+sticker[i][1];
            if (sticker[i][0] > sticker[i][1]) DP[i][0] = max(DP[i-1][1], DP[i-2][1]) + sticker[i][0];
            else DP[i][1] = max(DP[i-1][0], DP[i-2][0])+sticker[i][0];*/
            DP[i][0] = max(DP[i-1][1], DP[i-2][1]) + sticker[i][0];
            DP[i][1] = max(DP[i-1][0], DP[i-2][0]) + sticker[i][1];
        }
        cout << max(DP[n-1][0], DP[n-1][1]) << "\n";
    }
}
