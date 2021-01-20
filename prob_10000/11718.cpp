// getline (string) 사용함
// https://noosphere.tistory.com/5 여기 참고하면 좋을 거 같음 getline를 잘 쓰셨다.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
     do {
        getline(cin, s);
        cout << s << endl;
    } while (s!="\0") ;
}
