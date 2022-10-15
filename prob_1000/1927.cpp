//////////////////////////
// 2022.10.15 / kkarung //
//    priority queue    //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 시간 제한이 1초이므로 시간복잡도에 유의해야 한다
// priority queue를 사용하면 삽입, 삭제 모두 O(logn)이고 n번 반복하므로 O(nlogn)이다
// 최대 N은 10의 6승이므로 시간 조건을 만족한다
// 11279과 동일하되 최소값을 출력해야하므로 음수로 바꾸어서 넣고 출력할 때만 조심하자

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, x;
	priority_queue<int> pq;
	cin >> N;

	while(N--) {
		cin >> x;
		if (x) pq.push(x*-1);
		else if (pq.size() == 0) cout << "0\n";
		else {
			cout << pq.top()*-1 << '\n';
			pq.pop();
		}
	}
}
