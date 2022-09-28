//////////////////////////
// 2022.09.28 / kkarung //
//        queue         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 이번에는 왜 안 되는지 모르겠음

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool comp(const int& a, const int& b) {
	return a > b;
}

int main() {
	int t, n, m;
	int imp[101] = {0}; // 중요도 함수
	queue<int> p;
	cin >> t;

	while (t-->0) {
		cin >> n >> m;
		for (int i=0, temp; i<n; i++) {
			cin >> temp;
			imp[i] = temp;
			if (i==m) p.push(temp+10); 
			else p.push(temp);
		}

		sort(imp, imp+n, comp);

		for (int i=0;;) {
			if (p.front()%10 == imp[i]) {
				if (p.front()>10) { cout << i+1 << "\n"; break; }
				else { p.pop(); i++; }
			}
			else { p.push(p.front()); p.pop(); }
		}
	}
}
