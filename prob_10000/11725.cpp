//////////////////////////
// 2022.10.10 / kkarung //
//         Tree         //
//         BFS          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 서로 인접한 노드 정보를 저장하고, BFS를 이용해서 root부터 탐색한다

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 100001

int main() {
	int N, node1, node2;
	vector<vector<int>> edge;
	int parent[MAXN] = {0};
	bool visited[MAXN] = {false};
	queue<int> q;

	cin >> N;
	edge.resize(N+1);

	// 한 node에 인접한 node 전부 기록 (BFS의 인접 리스트)
	// 1 6 이면
	// edge[1][0 또는 1] = 6 & edge[6][0 또는 1] = 1
	for (int i=0; i<N-1; i++) {
		cin >> node1 >> node2;
		edge[node1].push_back(node2);
		edge[node2].push_back(node1);
	}

	// BFS
  // root 정보 저장
	q.push(1); visited[1] = true;
	while (q.size()) {
		int curr = q.front(); q.pop();
		visited[curr] = true;
		for (int adj: edge[curr]) {
			// 현재 node (curr)과 인접한 노드(adj) 중에 이미 방문한 노드가 있으면
			if (visited[adj]) {
				// BFS 특성상 그 노드는 이전 level의 노드이다
				// 게다가 현재 node와 인접해 있으므로 부모노드라고 추측할 수 있다.
				parent[curr] = adj;
			}
			// 만약 방문하지 않은 노드면 curr의 자식 노드이므로 queue에 넣자
			else q.push(adj);
		}
	}

	for (int i=2; i<=N; i++)
		cout << parent[i] << '\n';
}
