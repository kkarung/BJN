//////////////////////////
// 2022.10.13 / kkarung //
//     DP Top-Down      //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 평범한 DP인데 N이 10의 12승 제한이므로 메모리가 많이 필요해진다
// 따라서 배열이 아니라 계산할 필요가 있는 값만 구해서 map에 저장한다

#include <iostream>
#include <map>
using namespace std;

long long int N;
int P, Q;
map<long long int, long long int> DP;

long long int topdownDP (long long int n) {
	if (DP.find(n)!=DP.end()) return DP[n]; // 여기에 DP[0]일 때 전부 포함됨
	DP[n] = topdownDP(n/P)+topdownDP(n/Q);
	return DP[n];
}

int main() {
	cin >> N >> P >> Q;
	DP[0] = 1;
	cout << topdownDP(N);
}
