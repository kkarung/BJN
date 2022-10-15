//////////////////////////
// 2022.10.15 / kkarung //
//    priority queue    //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 11279, 1927과 거의 동일하되 절댓값을 취한 최솟값을 먼저 출력하고
// 동일한 절댓값을 가질 시에는 음수를 먼저 출력하는 것이 다르다
// pair first: 절댓값, second: 부호(true: 음수, false: 양수)
// priority_queue는 pair type일 때는 first 먼저 비교하므로 second는 first가 차순위로 비교하므로
// first는 1927처럼 -1을 곱해 최소힙으로 정렬하고
// second는 true(=1=음수일 때)와 false(=0=양수일 때)로 두어 그대로 최대힙 법칙이 적용되도록 한다

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, x;
	priority_queue<pair<int, bool>> pq;
	cin >> N;

	while(N--) {
		cin >> x;
		if (x>0) pq.push({x*-1, false});
		else if (x<0) pq.push({x, true});
		else if (pq.size() == 0) cout << "0\n";
		else {
			if (pq.top().second == true)
				cout << pq.top().first << '\n';
			else
				cout << pq.top().first*-1 << '\n';
			pq.pop();
		}
	}
}
