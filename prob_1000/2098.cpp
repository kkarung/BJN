//////////////////////////
// 2022.10.06 / kkarung //
//       비트마스크       //
//       DP + DFS      //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 방문한 마을을 비트로 기억해두고 DFS로 찾는다
// 
// 1102 문제와 매우 비슷

#include <iostream>
using namespace std;
#define MAXN 16
#define INF 1000000*16+1
#define VACANT -1

int N;
int W[MAXN][MAXN] = {0};
int DP[MAXN][1<<MAXN];

int DFS (int current, int state) {
	if (state == (1<<N)-1) { // 모든 곳을 들려서 태초마을로 돌아갈 차례인데
		if (!W[current][0]) return INF; // 시작점으로 돌아가는 길이 없으면 INF 반환
		return W[current][0]; // 시작점으로 돌아갈 수 있으면 돌아가는 비용 추가
	}
	if (DP[current][state]!=VACANT) // 이미 DP 계산했으면 다시 계산 안해도 됨 ㅂㅂ
		return DP[current][state];
	
	DP[current][state] = INF;
	for (int i=0; i<N; i++) {
		// i번째 마을에 이미 방문했거나, 가는 길이 없으면 continue
		if (state & (1<<i) || !W[current][i]) continue;
		// 방문할 수 있는 마을 중 최소 비용이 드는 길 찾기
		DP[current][state] = min(DP[current][state], W[current][i]+DFS(i, state|(1<<i)));
	}
	return DP[current][state];
}

int main() {
	cin >> N;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++) 
			cin >> W[i][j];

	for (int i=0; i<MAXN; i++)
		for (int j=0; j<(1<<MAXN); j++)
			DP[i][j] = VACANT;

	cout << DFS(0, 1) << '\n';
}
