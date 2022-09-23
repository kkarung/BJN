//////////////////////////
// 2022.09.23 / kkarung //
//        stack         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 괄호가 하나일때는 c를 증감시켜 계산할 수 있다
// '('가 들어오면 c++
// ')'가 들어오면 c-- 하되, c<0이 되거나, 끝났을 때 c>0이면 NO 출력

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, c;
    string input;
    stack<int> stack;
    cin >> n;

    while (n-->0) {
        cin >> input;
        c = 0;

        for (int i=0; i<input.length(); i++) {
            if (input[i] == '(') c++;
            else c--;
            if (c < 0) {
                cout << "NO\n"; break;
            }
        }
        if (c > 0) cout << "NO\n";
        else if (c == 0) cout << "YES\n";
    }
}
