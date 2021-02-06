/////////////////////////
// 2021.02.07 / kkarung /
//    DP / Bottom-up   //
/////////////////////////
///////////////////////// report ///////////////////////////////
// 용어 설명: DP[n]은 n자릿수 이천수의 개수
// 용어 설명: DP[0]은 시작하는 1을 제외한 모든 수가 0일 때를 의미함
// 목표: DP[n]을 구하자
// 계산: DP[n]=DP[n-2]+DP[n-3]+ ... + DP[1]+DP[0]
// ex) n=5일 때
// 1 0 [1 _ _] << DP[3]
// 1 0 0 [1 _] << DP[2]
// 1 0 0 0 [1] << DP[1]
// 1 0 0 0 0 << DP[0]

#include <iostream>
using namespace std;

int main() {
    int n;
    unsigned long DP[91] = {0};
    DP[1]=DP[0]=1;
    cin >> n;
    for (int i=2; i<=n; i++) {
        for (int j=0; j<i-1; j++) {
            DP[i] += DP[j];
        }
    }
    cout << DP[n] << "\n";
}

////////////////////////////////////////////////////////////////
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
