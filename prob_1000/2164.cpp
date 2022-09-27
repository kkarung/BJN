//////////////////////////
// 2022.09.27 / kkarung //
//        queue         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 큐에 숫자 넣고, 홀수번째에는 버림(pop), 짝수번째는 뒤에 붙임(push 후 pop)

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	queue<int> q;
	cin >> n;
	for (int i=1; i<=n; i++) q.push(i);

	for (int i=1; q.size() > 1; i++) {
		if (i%2!=0) q.pop();
		else {
			q.push(q.front());
			q.pop();
		}
	}
	cout << q.front();
}
