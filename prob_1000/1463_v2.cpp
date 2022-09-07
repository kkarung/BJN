/////////////////////////
// 2022.09.06/ kkarung //
//         DP          //
/////////////////////////
///////////////////////// report ///////////////////////////////
// Bottom-up 방식 이용
// 세 가지 선택지 중 가장 작은 횟수를 선택한다

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);

    dp[2] = 1;

    for (int i=3; i<=n; i++) {
        dp[i] = dp[i-1]+1;
        if (!(i%3)) dp[i] = min(dp[i], dp[i/3]+1);
        if (!(i%2)) dp[i] = min(dp[i], dp[i/2]+1);
    }

    cout << dp[n] << "\n";
}
