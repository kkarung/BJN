// substr 쓰는 방법도 있고 scanf 쓰는 방법도 있음
// 개인적으로는 scanf 쓰는 방법이 간단해 보임
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
