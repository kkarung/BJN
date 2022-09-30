//////////////////////////
// 2022.09.30 / kkarung //
//         DFS          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 한 그룹의 크기를 구하기 위해서 s를 두고 새로 DFS를 그 안에서 호출할 때마다 더해주는 방식

#include <iostream>
using namespace std;
#define MAXN 101

int N, M, K;
bool aisle[MAXN][MAXN] = {0};
bool visited[MAXN][MAXN] = {0};
int dc[4] = {1, -1, 0, 0};
int dr[4] = {0, 0, 1, -1};

int DFS(int r, int c) {
	int s = 1;
	visited[r][c] = true;

	for (int i=0; i<4; i++) {
		int pr = r + dr[i];
		int pc = c + dc[i];

		if (pr < 1 || pr > N || pc < 1 || pc > M) continue;
		if (aisle[pr][pc] == true && visited[pr][pc] == false)
			s += DFS(pr, pc);
	}

	return s;
}

int main() {
	int r, c, output = 0;
	cin >> N >> M >> K;

	for (int i=0; i<K; i++) {
		cin >> r >> c;
		aisle[r][c] = true;
	}

	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			if (aisle[i][j]==true && visited[i][j]==false)
				output = max(output, DFS(i, j));

	cout << output << "\n";
}
