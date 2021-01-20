// 2741에서 하나의 string으로 만드는 방법(https://www.acmicpc.net/source/24809285)을 참고했음
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";
    do {
        s+= to_string(n--)+"\n";
    } while (n > 0);
    cout << s;
}
