//////////////////////////
// 2022.10.01 / kkarung //
//         BFS          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 목적지부터 출발지까지 BFS 사용하여 최단거리 구하기
// level = 거리
// 2644 BFS 문제와 거의 동일하되 상하좌우를 체크해 벽을 뚫지 않았는지,
// maze[][] 값을 체크해 막힌 길은 아닌지 체크해야 하는 과정이 추가되었다.

#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define MAX 101

int main() {
	int N, M, qsize, level = 1;
	int maze[MAX][MAX] = {0};
	bool visited[MAX][MAX] = {false};
	cin >> N >> M;
	queue<pair<int,int>> q;
	pair<int, int> curr(N-1, M-1);
	int dy[4] = {1, -1, 0, 0};
	int dx[4] = {0, 0, 1, -1};
	for (int i=0; i<N; i++) {
		string t;
		cin >> t;
		for (int j=0; j<M; j++)
			maze[i][j] = t[j]-'0';
	}
	
	q.push(curr);
	visited[N-1][M-1] = true;
	
	while (q.size()) {
		qsize = q.size();
		for (int i=0; i<qsize; i++) {
			curr = q.front();
			q.pop();
			for (int j=0; j<4; j++) {
				int py = curr.first + dy[j];
				int px = curr.second + dx[j];
				if (py<0 || py>N-1 || px<0 || px>M-1)
          continue;
				if (maze[py][px] && !visited[py][px]) {
					visited[py][px] = true;
					q.push(make_pair(py, px));
					if (py==0 && px==0) break;
				}
			}
			if (q.back().first==0 && q.back().second==0) break;
		}
		level++;
		if (q.back().first==0 && q.back().second==0) break;
	}
	cout << level << "\n";
}
