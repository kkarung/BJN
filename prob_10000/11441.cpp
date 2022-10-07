//////////////////////////
// 2022.10.07 / kkarung //
//      prefix Sum      //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 11659와 완전히 동일

#include <iostream>
using namespace std;
#define MAXN 100001

int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	
	int N, M, n;
	int psum[MAXN]={0};
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> n;
		psum[i+1] = psum[i]+n;
	}
	cin >> M;
	while (M--) {
		int i, j;
		cin >> i >> j;
		cout << psum[j]-psum[i-1] << '\n';
	}
}
