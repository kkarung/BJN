//////////////////////////
// 2022.10.04 / kkarung //
//       백트래킹         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 모든 원소가 들어있을 경우, 없을 경우를 전부 계산하면 되는 건 동일하다
// 다만 저번에는 for문을 통해 전부 계산했다면 이번에는 DFS를 통해 모든 경우의 수를 계산하는 백트래킹 방식을 이용한다
// 

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
