/////////////////////////
// 2021.02.06 / kkarung /
//       DP / Both     //
/////////////////////////
///////////////////////// report ///////////////////////////////
// 함수 설명: combination = Bottom-up 방식 조합 계산
// 함수 설명: combination2 = Top-down 방식 조합 계산
// 중복 조합 개념을 이용하여 풀자
// 중복 포함 n개의 숫자를 뽑으면 알아서 순서가 배열된다고 생각하자.
// 그럼 10Hn = (n+9)Cn 을 계산하면 된다.
// 이 때 n은 1000 이하고 n+9까지 가능하므로 DP의 크기를 DP[1010][1001]로 설정해야 한다.

#include <iostream>
using namespace std;

int combination(int n, int r) {
    int DP[1010][1001];

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=r; j++) {
            if (i==j||j==0) DP[i][j] = 1;
            else DP[i][j] = (DP[i-1][j-1]+DP[i-1][j])%10007;
        }
    }

    return DP[n][r];
}

int combination2 (int n, int r) {
    if (n==r || r==0) return 1;
    return (combination(n-1, r-1)+combination(n-1, r))%10007;
}

int main() {
    int n;
    cin >> n;
    cout << combination(n+9, n) << "\n";
}
