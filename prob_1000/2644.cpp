//////////////////////////
// 2022.10.01 / kkarung //
//         BFS          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// BFS에선 시작점 ~ 목표 node의 level 차이가 최단거리라는 특징에 착안하였다
// 촌수관계를 기반으로 트리를 그리지 말고 목표하는 node를 가장 위에 두고 트리를 그리면
// 시작점(목표1) ~ 목표 node(목표2)의 level차이가 최단거리이다
// 보통 BFS에서 시작점부터 queue에 넣는 대신 목표1을 넣고 BFS를 돌린다
// 중간에 목표2를 발견하면 끝, 발견하지 못하면 친척 관계가 아니므로 -1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, N1, N2, M, x, y;
	int qsize, distance = 0;
	cin >> N >> N1 >> N2 >> M;
	queue<int> q;
	vector<vector<int>> edge(N+1);
	vector<bool> visited(N+1, false);

  // 인접리스트 설정 중
	for (int i=0; i<M; i++) {
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

  // 목표1을 queue에 넣고 BFS 시작
	q.push(N1);
	visited[N1] = true;
	while (!q.empty()) {
		qsize = q.size();
    // for문으로 같은 level의 node 훑어봄
		for (int i=0; i<qsize; i++) {
			int curr = q.front();
			q.pop();
      // 다음 level의 node 삽입
			for (int next : edge[curr]) {
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
				if (next == N2)
					break;
			}
		}
		distance++; // = level
    // 목표2를 찾으면 더 이상 BFS 돌릴 필요 없음
		if (q.back() == N2)
			break;
	}
	if (q.empty()) cout << "-1\n";
	else cout << distance << "\n";
}
