
// 이건 이렇게 풀었지만 그냥 scanf("%d,%d", &a, &b);로 받아야 변수 하나 줄어들어서 좋을 듯
#include <iostream>
using namespace std;

int main() {
    int a,b,n;
    char s; 
    cin >> n;
    while (n-->0) {
        cin >> a >> s >> b;
        cout << a+b << endl;
    }
}
