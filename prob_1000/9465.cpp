/////////////////////////
// 2022.09.16/ kkarung //
//         DP          //
/////////////////////////
///////////////////////// report ///////////////////////////////
// DP[i][0]은 0번째 row, i번째 column에 위치한 스티커를 포함했을 때 최대 점수
// DP[i][1]은 1번째 row, i번째 column에 위치한 스티커를 포함했을 때 최대 점수
// 최댓값이 나오는 3가지 경우
// DP[i][1]는 < DP[i-1][0] 또는 DP[i-2][0] > 과 [i][1]의 점수를 합한 값이다 (대각선으로 스티커를 획득할 수 있으므로)
// DP[i][0]는 < DP[i-1][1] 또는 DP[i-2][1] > 과 [i][0]의 점수를 합한 값이다 (대각선으로 스티커를 획득할 수 있으므로)
// DP[i-3][0]을 고려하지 않는 이유는 [i-3][0] 에서 [i][1]로 오는 것보다는 [i-3][0] -> [i-2][1] -> [i-1][0] -> [i][1] 로 오는 것이 유리하기 때문이다.

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
            DP[i][0] = max(DP[i-1][1], DP[i-2][1]) + sticker[i][0];
            DP[i][1] = max(DP[i-1][0], DP[i-2][0]) + sticker[i][1];
        }
        cout << max(DP[n-1][0], DP[n-1][1]) << "\n";
    }
}
