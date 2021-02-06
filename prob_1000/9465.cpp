/////////////////////////
// 2021.02.07 / kkarung /
//    DP / Bottom-up   //
/////////////////////////
///////////////////////// report ///////////////////////////////
// 용어 설명: DP[0][i]는 0번째 행 i번째 열까지의 최댓값
// 용어 설명: score[i][j]은 문제에서 주어진 점수
// 계산: 이전 대각선의 DP들을 비교해서 큰 값을 선택하자.
// DP[1][i]는 < DP[0][i-1] 또는 DP[0][i-2] > 과 [1][i]의 점수를 합한 값이다 (대각선으로 스티커를 획득할 수 있으므로)
// DP[0][i]는 < DP[1][i-1] 또는 DP[1][i-2] > 과 [0][i]의 점수를 합한 값이다 (대각선으로 스티커를 획득할 수 있으므로)
// DP[0][i-3]을 고려하지 않는 이유는 [0][i-3] 에서 [1][i]로 오는 것보다는 [0][i-3] -> [1][i-2] -> [0][i-1] -> [1][i] 로 오는 것이 유리하기 때문이다.
// 이해 안 되면 https://m.blog.naver.com/occidere/220786307316 참고

#include <iostream>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

int main() {
    int t, n;
    int DP[2][100001], score[2][100001];
    score[0][0] = score[1][0] = 0;
    cin >> t;
    while (t-->0) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> score[0][i];
        for (int i=1; i<=n; i++) cin >> score[1][i];
        DP[0][0] = DP[1][0] = 0;
        DP[0][1] = score[0][1]; DP[1][1] = score[1][1];
        for (int i=2; i<=n; i++) {
            DP[0][i] = MAX(DP[1][i-1], DP[1][i-2]) + score[0][i];
            DP[1][i] = MAX(DP[0][i-1], DP[0][i-2]) + score[1][i];
        }
        cout << MAX(DP[0][n], DP[1][n]) << "\n";
    }
}
