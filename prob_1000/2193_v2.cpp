// 피보나치 수열로 점화식을 만들수도 있다
// DP[i] = DP[i-1]+DP[i-2];
// ex) n=5일 때
// 1 0 [1 _ _] << DP[3]
// 1 0 [0 _ _] << 이 때는 백의 자리 숫자가 0일 때 즉, DP[4]와 동일하다
//   1 [0 _ _] << DP[4]

#include <iostream>
using namespace std;

int main() {
    int n;
    unsigned long DP[91] = {0};
    DP[2]=DP[1]=DP[0]=1;
    cin >> n;
    for (int i=3; i<=n; i++)
        DP[i] = DP[i-1]+DP[i-2];
    cout << DP[n] << "\n";
}
