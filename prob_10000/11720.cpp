// char을 입력 받으면 한 글자씩 입력 받을 수 있음을 깜빡했음
// https://blockdmask.tistory.com/78 참고함
# include <iostream>
using namespace std;

int main() {
    int n, sum=0;
    char c;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> c;
        sum += c-'0';
    }
    cout << sum;
}
