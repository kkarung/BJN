#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, sum = 0;
	string s;
	cin >> N >> s;
  
	for (int i=0; i<N; i++)
    sum += s[i]-'0';
	cout << sum << '\n';
}
