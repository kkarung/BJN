//////////////////////////
// 2022.10.06 / kkarung //
//       비트마스크       //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 21자리 이진수(0의 자리 버렷)를 flag로 1부터 20이 들어있는지 없는지 관리할 수 있다
// 13~15번째 줄 코드 추가 안 하면 시간 초과 뜸

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	string cmd;
	int M, opd, bit = 0;
	cin >> M;

	while (M--) {
		cin >> cmd;
		if (cmd == "all") 
			bit = (1<<21)-1;
		else if (cmd == "empty")
			bit = 0;
		else {
			cin >> opd;
			if (cmd=="add")
				bit |= 1<<opd;
			else if (cmd=="remove")
				bit &= ~(1<<opd);
			else if (cmd=="check")
				cout << ((bit & 1<<opd) ? 1 : 0) << '\n';
			else if (cmd=="toggle")
				bit ^= (1<<opd);
		}
	}
}
