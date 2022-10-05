//////////////////////////
// 2022.10.05 / kkarung //
//       백트래킹         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 기본적인 백트래킹 문제

#include <iostream>
using namespace std;
#define OOB 21

const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {1, -1, 0, 0};

int R, C, M = 0;
string board[OOB] = {};
bool visited[OOB][OOB] = {false};
bool isUsed[26] = {false};

void backTracking(int r, int c, int cnt) {
	M = max(M, cnt+1); // 최댓값 갱신 (가능하다면)
	isUsed[board[r][c]-'A']=true;
	for (int i=0; i<4; i++) {
		int nr = r+dr[i];
		int nc = c+dc[i];
		if (nr<0||nr>=R||nc<0||nc>=C) continue;
		if (!isUsed[board[nr][nc]-'A']) // 가지 않았던 장소라면
			backTracking(nr, nc, cnt+1);
	}
	isUsed[board[r][c]-'A']=false;
}

int main() {
	cin >> R >> C;
	for (int i=0; i<R; i++)
		cin >> board[i];
	
	backTracking(0, 0, 0);
	cout << M;
}
