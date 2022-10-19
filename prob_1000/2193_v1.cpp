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
