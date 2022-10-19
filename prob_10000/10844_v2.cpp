//////////////////////////
// 2022.10.19 / kkarung //
//          DP          //
//       Bottom-up      //
//////////////////////////
////////////////////////// report ////////////////////////////////
// DP[i][j]: 자릿수가 i일 때, 끝자리가 j인 수의 계단수 개수
// i-1 자릿수를 가진 수에 뒤에 붙일 수 있는 수의 경우를 나눠서 i 자릿수가 되도록 붙인다

#include <iostream>
using namespace std;
#define MAXN 101

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, sum = 0;
	int DP[MAXN][10] = {0};
	cin >> N;
	for (int j=1; j<10; j++) DP[1][j] = 1;

	for (int i=2; i<=N; i++) {
    // 0으로 끝날 때
		DP[i][0] = DP[i-1][1];
    // 1~8로 끝날 때
		for (int j=1;j<9; j++) {
			DP[i][j] = DP[i-1][j-1]+DP[i-1][j+1];
			DP[i][j] %= 1000000000;
		}
    // 9로 끝날 때
		DP[i][9] = DP[i-1][8];
	}

  // 출력
	for (int j=0; j<10; j++) {
		sum += DP[N][j];
		sum %= 1000000000;
	}

	cout << sum;
}
