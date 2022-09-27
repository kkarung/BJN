//////////////////////////
// 2022.09.27 / kkarung //
//        queue         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// pair.first = 우선도, pair.second = 목표인지(true) 아닌지(false)
// sort로 두고 내림차순 정렬하되, 같은 값은 오름차순 정렬하는 코드를 구현했는데
// 예제1의 case 03을 넣고 돌리면
// [9, 0]
// [1, 1]
// 2
// [1, 0]
// [1, 0]
// [1, 0]
// [1, 0]
// 이렇게 된다. 실제로는 [9, 0]가 지난 이후로부터 오름차순 정렬이 되어야 하니까
// 이 코드로는 문제를 해결할 수 없다

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool comp(const pair<int, bool>& a, const pair<int, bool>& b) {
	return a.first>b.first;
}

int main() {
	int t, n, m, i;
	cin >> t;
	vector<pair<int, bool> > p;
	vector<pair<int, bool> >::iterator iter;

	while (t-->0) {
		cin >> n >> m;
		for (i=0; i<n; i++) { 
			int temp; cin >> temp;
			if (i==m) p.push_back(make_pair(temp, true));
			else p.push_back(make_pair(temp, false));
		}
		sort(p.begin(), p.end(), comp);
		for (iter = p.begin(), i=1; iter!=p.end(); iter++, i++) {
			printf("[%d, %d]\n", iter -> first, iter->second);
			if (iter -> second == true)
				cout << i << "\n";
		}
	}
}
