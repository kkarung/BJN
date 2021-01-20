// substr 쓰는 방법도 있고 scanf 쓰는 방법도 있음
// 개인적으로는 scanf 쓰는 방법이 간단해 보임
// https://www.acmicpc.net/source/24809285(하나의 string으로 만들어서 출력하는 방법)도 있음
#include <iostream>
using namespace std;

int main() {
    int i=0;
    string s;
    cin >> s;
    while (i < s.length()) {
        cout << s[i];
        if (++i%10==0) cout << endl;
    }
}
