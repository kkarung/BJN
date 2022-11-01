//////////////////////////
// 2022.11.01 / kkarung //
//          DP          //
//       Bottom-Up      //
//////////////////////////
////////////////////////// report ////////////////////////////////
// DP[i]: i번째 원소를 포함한 부분배열 중 가장 합이 큰 것
// 유용했던 TC: 5 1 8 2 3 9

#include <iostream>
using namespace std;
#define MAXN 1001

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M = 0;
	int A[MAXN], DP[MAXN] = {0};
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
		for (int j=0; j<i; j++)
			// i번째 원소의 부분배열이 될 수 있는 것(A[j]<A[i]) 중에 가장 큰 부분배열(DP[i]<DP[j]) 찾는 과정
			// DP[i]에 아직 A[i]를 안 더했음, 더했으면 아래에 DP[i] < DP[j]+A[i]로 썼을 것
			if (A[j] < A[i] && DP[i] < DP[j])
				DP[i] = DP[j];
		DP[i] += A[i];
		M = max(M, DP[i]);
	}

	cout << M;
}
