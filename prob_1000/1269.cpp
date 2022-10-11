//////////////////////////
// 2022.10.11 / kkarung //
//         SET          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 이진 검색 트리(BST)를 공부하면서 푼 문제지만 그 개념은 SET library 안에만 들어있음

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
