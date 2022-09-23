//////////////////////////
// 2022.09.23 / kkarung //
//        stack         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 말 그대로 stack 기초 함수 구현하는 문제
// 근데 구현 안 했음

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    string cmd;
    stack<int> stack;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> cmd;
        if (cmd == "push") {
            int x; cin >> x;
            stack.push(x);
        } 
        else if (cmd == "pop") {
            if (stack.empty())
                cout << "-1\n";
            else {
                cout << stack.top() << "\n"; stack.pop();
            }
        }
        else if (cmd == "size")
            cout << stack.size() << "\n";
        else if (cmd == "empty")
            cout << stack.empty() << "\n";
        else if (cmd == "top") {
            if (stack.empty())
                cout << -1 << "\n";
            else
                cout << stack.top() << "\n";
        }
    }
}
