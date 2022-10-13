//////////////////////////
// 2022.10.13 / kkarung //
//         Map          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 이진 검색 트리(BST) 예제로서 Map을 사용하는 문제
// 포켓몬 도감은 영어로 pokedex라고 한다

#include <iostream>
#include <map>
#include <cctype>
using namespace std;
#define MAXN 100001

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	string pokedex1[MAXN];
	map<string, int> pokedex2;
	cin >> N >> M;
	for (int i=1; i<=N; i++) {
		cin >> pokedex1[i];
		pokedex2.insert({pokedex1[i], i});
	}
	
	while (M--) {
		string s;
		cin >> s;
		if (isdigit(s[0]))
			cout << pokedex1[stoi(s)] << '\n';
		else
			cout << pokedex2[s] << '\n';
	}
}
