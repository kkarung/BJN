//////////////////////////
// 2022.10.05 / kkarung //
//       백트래킹         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// L개의 문자를 선택하고, 선택한 문자가 모든 조건을 만족하면 출력
// 그렇지 않다면 그 문자를 배제하고 다음 문자를 선택하고 위의 과정 반복
// 45~48과 57~69에서 동일한 로직이 반복되는 만큼 별로 좋지 못한 코드

#include <iostream>
#include <algorithm>
using namespace std;
#define OOB 16

int L, C;
char input[OOB] = {0};
bool cand[OOB] = {false};
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(int i) {
    if (input[i] == 'a' ||
       input[i] == 'e' ||
       input[i] == 'i' ||
       input[i] == 'o' ||
       input[i] == 'u')
		return true;
	return false;
}

void backtracking (int i, int l, int v) {
	// i번째 원소를 선택함
	cand[i] = true;
	l++;
	if (isVowel(i)) v++; // 모음일 때 고려
	
	if (l==L) { // L개의 문자를 선택했을 때
		if (v>=1 && l-v>=2) { // 조건에 만족하면 출력
			for (int j=0; j<C; j++)
				if (cand[j])
					cout << input[j];
			cout << "\n";
		}
		return; // 이후로 다른 문자 선택해도 L+1개가 되므로 무조건 만족할 수 없다 따라서 여기서 이 문자를 선택하기 전으로 돌아가야 함
	}
	for (int j=i+1; j<C; j++) {
		backtracking(j, l, v); // i번째 문자를 선택하지 않고, 선택한 다음 문자가 i+1번째~C-1번째 문자일 경우
		cand[j] = false;
	}

}

int main() {
	cin >> L >> C;
	for (int i=0; i<C; i++) cin >> input[i];
	sort(input, input+C);
	
	for (int i=0; i<=C-L; i++) {
		backtracking(i, 0, 0);
		cand[i]=false;
	}
}
