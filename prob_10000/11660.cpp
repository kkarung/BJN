//////////////////////////
// 2022.10.07 / kkarung //
//      prefix Sum      //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 1차원이 2차원이 된 것을 제외하면 11659 문제와 동일한 방식으로 풀 수 있다
// psum[i][j]은 (0,0)~(i-1,j-1)까지의 합이므로
// psum[i][j] = psum[i][j-1]+psum[i-1][j]-psum[i-1][j-1]+(i-1, j-1)번째 요소
// 계산하는 데 시간복잡도는 O(1)이고 M번 계산해야 하므로 O(M)

#include <iostream>
using namespace std;
#define MAXN 1025

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, n;
	int psum[MAXN][MAXN] = {0};

	cin >> N >> M;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> n;
			psum[i+1][j+1] = psum[i][j+1]+psum[i+1][j]-psum[i][j]+n;
		}
	}
	
	while (M--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--;
		cout << psum[x2][y2]-psum[x2][y1]-psum[x1][y2]+psum[x1][y1] << '\n';
	}
}
