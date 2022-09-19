//////////////////////////
// 2022.09.19 / kkarung //
//         list         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 처음엔 list로 풀다가 귀찮아서 queue로 변환
// front에서만 삭제하고 앞 뒤로 원소 위치만 삽입/삭제해서 바꿔주면 됨

#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main() {
    int n;
    deque<pair<int, int> > ballon;
    cin >> n;

    for (int i=0, t; i<n; i++) { cin >> t; ballon.push_back(make_pair(i+1, t)); }

    while (n-->0) {
        int num = ballon.front().second;
        cout << ballon.front().first << " ";
        ballon.pop_front();

        if (num < 0) {
            for (int i=0; i>num; i--) {
                ballon.push_front(ballon.back());
                ballon.pop_back();
            }
        }
        else if (num > 0) {
            for (int i=0; i<num-1; i++) {
                ballon.push_back(ballon.front());
                ballon.pop_front();
            }
        }
    }


}
