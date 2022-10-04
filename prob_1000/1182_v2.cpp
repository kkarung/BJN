//////////////////////////
// 2022.10.04 / kkarung //
//       백트래킹         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 모든 원소가 들어있을 경우, 없을 경우를 전부 계산하면 되는 건 동일하다
// 다만 저번에는 for문을 통해 전부 계산했다면 이번에는 DFS를 통해 모든 경우의 수를 계산하는 백트래킹 방식을 이용한다
// 22번째 줄에서 DFS가 끝나지도 않았는데 count할 수 있는 건 if 조건에서 sum+input[i] 즉, input[i]를 더하기 때문
// 예를 들어 주어진 예제에서 i:2일 때 합이 S가 되었다면 이 때의 경우는 _ _ 1 0 0 (1: 들어감, 0: 들어가지 않음)이고,
// 더 깊게 들어갔을 때 i:4일 때 합이 S가 되었다면 이 때의 경우는 _ _ _ _ 1 이므로 무조건 그 전에 만족했을 경우와 다르다

#include <iostream>
using namespace std;
#define OOB 21

int N, S, cnt = 0;
int input[OOB] = {0};

// i: 이번에 들어갈 input의 index, sum: 현재까지의 합
void DFS (int i, int sum) {
	if (i>=N) return;
	if (sum+input[i] == S) cnt++;
	DFS(i+1, sum);
	DFS(i+1, sum+input[i]);
}

int main() {
	cin >> N >> S;
	for (int i=0; i<N; i++) { cin >> input[i]; }
	
	DFS(0, 0);

	cout << cnt;
}
