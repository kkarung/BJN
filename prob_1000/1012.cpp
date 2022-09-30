//////////////////////////
// 2022.09.30 / kkarung //
//         DFS          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// "인접한 배추에 인접한 범위"까지 모두 벌레 하나가 책임질 수 있다
// 1 1 1 \n 1 1 1 \n 1 1 1 의 밭도 벌레 하나가 책임질 수 있다는 뜻
// DFS 또는 BFS로 인접하고 있는 땅의 개수를 확인하자
// 인접 리스트로 푼다고 가정할 때 pair를 쓰지 않으려면
// (x, y) 좌표를 하나의 숫자로 변환한 다음 (0 1 2 3 \n 4 5 6 7 ...)
// 좌표의 인접한 값을 계산해야 하는데 이럴 경우 첫번째 줄 가장 마지막 3과
// 두번째 줄 가장 처음 4가 인접하지 않는 것을 계산해야 하므로 귀찮다
// 따라서 인접 리스트가 아닌 전체 행렬을 전부 접근해가면서 푼다
// 따라서 O(n^2)의 시간복잡도를 가진다

#include <iostream>
using namespace std;
#define MAXN 50

int T, M, N, K;
int map[MAXN][MAXN] = {0};
int visited[MAXN][MAXN] = {0};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y) {
	visited[x][y] = 1;
	for (int i=0; i<4; i++) {
		if (x+dx[i]>=0 && x+dx[i]<M && y+dy[i]>=0 && y+dy[i]<N) {
			if (map[x+dx[i]][y+dy[i]]==1 && visited[x+dx[i]][y+dy[i]]==0)
				DFS(x+dx[i], y+dy[i]);
		}
	}
}

int main() {
	int x, y, worm;
	cin >> T;
	while (T--) {
		worm = 0;
		cin >> M >> N >> K;
		
		for (int i=0; i<M; i++) {
			for (int j=0; j<N; j++) {
				map[i][j] = 0; visited[i][j] = 0;
			}
		}

		for (int i=0; i<K; i++) {
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int i=0; i<M; i++) {
			for (int j=0; j<N; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					DFS(i,j);
					worm++;
				}
			}
		}
		cout << worm << "\n";
	}
}
