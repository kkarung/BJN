//////////////////////////
// 2022.10.06 / kkarung //
//       비트마스크       //
//       DP + DFS      //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 발전소가 켜진 상태를 비트로 표현(i번째 발전소가 켜졌으면 i번째 비트를 1로 두기)
// DFS를 사용하되 기존에 계산한 값이 있으면 가져와서 사용 (DP)
// 2098 문제와 매우 비슷
// https://blog.naver.com/kks227/220787042377 여기 보고 공부했음

#include <iostream>
using namespace std;
#define MAXN 16
#define VACANT -1
#define INF 37*17

int N, P;
string onOff;
int pp[MAXN][MAXN] = {0};
int DP[1<<MAXN] = {0};

// 이 상태(state)에서 P개 이상의 발전소가 켜지기 위해 드는 최소비용
// 예를 들면 110에서 111이 되기 위해 드는 최소 비용
int DFS (int state, int p) {
	if (p >= P) return 0; // P개 밝혔으면 더 비용 들지 않음
	if (DP[state]!=VACANT) return DP[state];
	
	DP[state] = INF;
	for (int i=0; i<N; i++) {
		if (!(state&(1<<i))) continue;
		// 출발점이 고장나지 않고
		for (int j=0; j<N; j++) {
			if (state&(1<<j)) continue;
			// 도착점이 고장나 있을 때만
			DP[state] = min(DP[state], pp[i][j]+DFS(state|(1<<j), p+1));
      // 계산할 필요성 있음
		}
	}
	return DP[state];
}

int main() {
	int state = 0, p = 0;
	cin >> N;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++) 
			cin >> pp[i][j];
	cin >> onOff >> P;

	for (int i=0; i<(1<<MAXN); i++) DP[i] = VACANT; // DP 초기화

	for (int i=0; onOff[i]; i++)
		if (onOff[i]=='Y') {
			state |= 1<<i; p++; // 켜진 발전소 업데이트 및 개수 세기
		}

	cout << DFS(state, p) << "\n";
}
