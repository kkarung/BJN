#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			if (N-j<i) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}
