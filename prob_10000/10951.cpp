//////////////////////////
// 2022.10.17 / kkarung //
//        입출력          //
//////////////////////////
////////////////////////// report ////////////////////////////////
// https://skku.goorm.io/qna/4241을 보면 cin은 cin 객체를 반환하지만
// if나 while안에 들어갈 시 operator에 의해 연산 성공/실패에 대한 bool값을 반환함을 알 수 있다

#include <iostream>
using namespace std;

int main() {
    int a,b;
    while (cin >> a >> b) cout << a+b << '\n';
}
