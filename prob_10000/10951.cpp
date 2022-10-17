//////////////////////////
// 2022.10.17 / kkarung //
//        입출력          //
//////////////////////////
////////////////////////// report ////////////////////////////////
// https://skku.goorm.io/qna/4241을 보면 cin의 return형이 연산 성공/실패에 대한 bool 값임을 알 수 있다

#include <iostream>
using namespace std;

int main() {
    int a,b;
    while (cin >> a >> b) cout << a+b << '\n';
}
