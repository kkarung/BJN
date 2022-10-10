// 2022.10.10 / kkarung //
//         Tree         //
//         DFS          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 한 node를 잡고 DFS를 실행하여 node가 사이클이면

#include <iostream>
#include <vector>
using namespace std;
#define MAXN 501

bool visited[MAXN] = {false};
vector<vector<int>> edge;

// Tree인지 Cycle인지 파악
bool DFS(int curr, int prev) {
	visited[curr] = true;
	for (int adj : edge[curr]) {
    // 이 DFS를 호출한 노드(prev)도 아래 if문에서는 false를 return하므로 cycle로 걸리지 않게 하려면 이 경우를 제외해야함
		if (prev == adj) continue;
    // 인접 노드를 이미 방문했다면 cycle
		if (visited[adj]) return false;
    // DFS 결과 false를 return하면 cycle
		if (!DFS(adj, curr)) return false;
	}
	// 트리가 문제 없이
	return true;
}

int main() {
	int N, M, T = 0, cnt; // cnt: 트리 개수 count

	while (true) {
		cin >> N >> M;
		// TEST CASE 종료 조건
		if (!N&&!M) break;

		// 인접 리스트 & visited && 트리 개수 cnt 초기화
		edge.resize(N+1);
		for (int i=1; i<=N; i++) {
			visited[i] = false;
			edge[i].clear();
		}
		cnt = 0;

		// edge 입력 받음
		while (M--) {
			int node1, node2;
			cin >> node1 >> node2;
			edge[node1].push_back(node2);
			edge[node2].push_back(node1);
		}

		// 고립된 component가 있을 경우를 대비하여 for문으로 N번째 요소까지 전부 탐색
		for (int i=1; i<=N; i++)
			if (!visited[i]) 
				if (DFS(i, 0)) cnt++;

		cout << "Case " << ++T << ": ";
		if (cnt==0) cout << "No trees.\n";
		else if (cnt==1) cout << "There is one tree.\n";
		else cout << "A forest of " << cnt << " trees.\n";
	}
}
