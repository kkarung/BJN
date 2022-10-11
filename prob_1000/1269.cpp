//////////////////////////
// 2022.10.11 / kkarung //
//         SET          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 이진 검색 트리(BST)를 공부하면서 푼 문제지만 그 개념은 SET library 안에만 들어있음
// 처음에는 A,B 집합이 가능한 최대 원소 개수만큼의 배열을 만들고 n이 들어오면 arr[n]에 추가하는 형식으로
// 풀어 O(n)으로 해결하려고 했는데 최대 원소 개수가 10의 8승이라 포기함
// 대신 삽입 제외하고 탐색의 시간복잡도는 탐색 O(logn)x 탐색 횟수 O(n) = O(nlogn)

#include <iostream>
#include <set>
using namespace std;

int main() {
	int A, B, temp, insec=0;
	set<int> s;
	set<int>::iterator iter;
	cin >> A >> B;

	for (int i=0; i<A; i++) {
		cin >> temp;
		s.insert(temp);
	}

	for (int i=0; i<B; i++) {
		cin >> temp;
		iter = s.find(temp);
		if (iter!=s.end()) insec++;
	}

	cout << A+B-insec*2 << '\n';
}
