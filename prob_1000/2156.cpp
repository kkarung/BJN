/////////////////////////
// 2021.02.09 / kkarung /
//    DP / Bottom-up   //
/////////////////////////
///////////////////////// report ///////////////////////////////
// 용어 설명: DP[i]는 i번째 포도주까지 최대로 먹은 양
// 용어 설명: wine[i] i번째 포도주의 양
// 계산: i번째까지의 포도주 중 최대로 먹을 수 있는 모든 경우의 수를 비교하자
// - 경우의 수를 나열해보자
// i-3 i-2 i-1 i [포도주 번호]
//  -   x   o  o   DP[i-3] + wine[i-1] + wine[i]
//  -   -   x  o   DP[i-2] + wine[i]
//  -   -   -  x   DP[i-1]

#include <iostream>
#define MAX(a, b, c) (((a) > (b)) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
using namespace std;

int main() {
    int n;
    int wine[10001], DP[10001];
    cin >> n;
    for (int i=1; i<=n; i++) cin >> wine[i];
    
    DP[0] = 0; DP[1] = wine[1]; DP[2] = MAX(wine[0]+wine[2], wine[1]+wine[2], DP[1]);
    for (int i=3; i<n; i++) {
        DP[i] = MAX(DP[i-1], DP[i-2]+wine[i], DP[i-3]+wine[i-1]+wine[i]);
    }
    cout << DP[n-1] << "\n";
}
