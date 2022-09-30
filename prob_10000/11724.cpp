//////////////////////////
// 2022.09.30 / kkarung //
//         DFS          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 인접리스트로 풀었으므로 O(M+N)
// 다만 문제를 잘 읽고 인덱스 범위를 잘 파악할 것

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;

void DFS(int n) {
	visited[n] = true;
	for (int m: edge[n])
		if (visited[m] == false)
			DFS(m);
}

int main() {
	int N, M, u, v, adj=0;
	cin >> N >> M;

	edge.reserve(N+1);
	visited.resize(N+1, false);

	for (int i=0; i<M; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	for (int i=1; i<=N; i++) {
		if (visited[i] == false) {
			adj++; DFS(i);
		}
	}
	cout << adj << "\n";
}
