//////////////////////////
// 2022.10.01 / kkarung //
//         BFS          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 이 경우에는 8방향으로 이동할 수 있다는 것 외에는 2178과 동일한 문제
// 38번째 줄에 if 조건과 40번째 줄 if 조건을 한 번에 쓰면 OOB 일어날 수 있으니 주의

#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define MAX 301

int main() {
	int t, I, x1, y1, x2, y2;
	int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

	cin >> t;
	while (t--) {
		cin >> I >> x1 >> y1 >> x2 >> y2;
		int qsize, level = 0;
		queue<pair<int, int>> q;
		bool visited[MAX][MAX]={false};

		q.push(make_pair(y1, x1));
		visited[y1][x1] = true;
		while (!visited[y2][x2]) {
			qsize = q.size();
			for (int i=0; i<qsize; i++) {
				pair<int,int> curr = q.front();
				q.pop();
				for (int j=0; j<8; j++) {
					int py = curr.first + dy[j];
					int px = curr.second + dx[j];

					if (px<0 || px>=I || py<0 || py>=I)
						continue;
					if (!visited[py][px]) {
						visited[py][px] = true;
						q.push(make_pair(py, px));
					}
				}
			}
			level++;
		}
		cout << level << "\n";
	}
}
