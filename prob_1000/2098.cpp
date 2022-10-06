//////////////////////////
// 2022.10.06 / kkarung //
//        비트마스크       //
//          DFS         //
//     DP + Top-Down    //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 방문한 마을을 비트로 표현(i번째 마을에 방문했으면 i번째 비트를 1로 두기)
// DFS를 사용하되 기존에 계산한 값이 있으면 가져와서 사용 (DP)
// 1102 문제와 매우 비슷
// https://blog.naver.com/kks227/220787042377 여기 보고 공부했음

#include <iostream>
using namespace std;
#define MAXN 16
#define INF 1000000*16+1
#define VACANT -1

int N;
int W[MAXN][MAXN] = {0};
int DP[MAXN][1<<MAXN];

// 현재 상태(state)에서 모든 마을에 방문하기 위해 드는 최소 비용
int DFS (int current, int state) { // current: 현재 위치, state: 방문한 마을을 bit로
	if (state == (1<<N)-1) { // 모든 곳을 들려서 태초마을로 돌아갈 차례인데 (bit가 전부 1일 때)
		if (!W[current][0]) return INF; // 시작점으로 돌아가는 길이 없으면, INF 반환
		return W[current][0]; // 그렇지 않고 시작점으로 돌아갈 수 있으면, 돌아가는 비용 추가
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

	// DP 초기화
	for (int i=0; i<MAXN; i++)
		for (int j=0; j<(1<<MAXN); j++)
			DP[i][j] = VACANT;

	cout << DFS(0, 1);
}
