/////////////////////////
// 2021.02.05 / kkarung /
//   DP / Bottom-up
/////////////////////////

#include <iostream>
using namespace std;

int main() {
    int n;
    int list[1001] = {0};
    list[1] = 1; list[2] = 3;
    cin >> n;
    for (int i=3; i<=n; i++) {
        list[i] = list[i-1]+2*list[i-2];
        list[i] %= 10007;
    }
    cout << list[n];
}
// 짝수일 때: list[i] = list[i-2]*3+list[i-3]*2 (이 때는 list[i-1] = list[i-2]+list[i-3]*2 가 된다)
// 홀수일 때: list[i] = list[i-1]+list[i-2]*2
// 하나로 합칠 수 있다 => list[i-1]+list[i-2]*2
