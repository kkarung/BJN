//////////////////////////
// 2022.10.16 / kkarung //
//          DP          //
//       Top-Down       //
//////////////////////////
///////////////////////// report ///////////////////////////////
// DP 기본 문제
// n: n번째 집, c: 칠하고 싶은 색 (R, G, B는 0, 1, 2에 대응)
// n번째 집을 c로 칠할 때 필요한 최소 비용은
// n-1번째까지의 집을 c가 아닌 색으로 칠했을 때의 최소비용 + n번째 집을 c로 칠하는데 드는 비용

#include <iostream>
using namespace std;
#define MAXN 1001
#define MIN(x, y) (x < y ? x : y)
#define MIN3(x, y, z) (MIN(x, y) < z ? MIN(x, y) : z)

int N;
int RGB[MAXN][3] = {0};
int DP[MAXN][3] = {0};

int topdownDP(int n, int c) {
	if (DP[n][c]==0)
		DP[n][c] = MIN(topdownDP(n-1, (c+1)%3), topdownDP(n-1, (c+2)%3)) + RGB[n][c];
	return DP[n][c];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i=0; i<N; i++) cin  >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	
	DP[0][0] = RGB[0][0]; DP[0][1] = RGB[0][1]; DP[0][2] = RGB[0][2];
	cout << MIN3(topdownDP(N-1, 0), topdownDP(N-1, 1), topdownDP(N-1, 2));
}
