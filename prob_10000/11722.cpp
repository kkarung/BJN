//////////////////////////
// 2022.11.01 / kkarung //
//          DP          //
//       Bottom-Up      //
//////////////////////////
////////////////////////// report ////////////////////////////////
// DP[i]: i번째가 포함된 부분배열 중에서 가장 길이가 긴 것 
// 11055.cpp와 유사하지만, 이 문제는 "길이가 긴" 걸 찾고, 저 문제는 "원소의 크기가 큰" 걸 찾는다는 점이 다르다

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
		DP[i] = 1;
		for (int j=0; j<i; j++)
			// DP[i]와 DP[j]가 같아도 DP[i]는 DP[j]의 배열에서 i번째 원소가 더 포함된다
			if (A[j]>A[i] && DP[i]<=DP[j])
				DP[i] = DP[j]+1; // DP[j]에 i번째 원소를 추가한 것이 DP[i]
		M = max(M, DP[i]);
	}

	cout << M;
}
