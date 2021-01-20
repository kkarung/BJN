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
