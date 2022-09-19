//////////////////////////
// 2022.09.19 / kkarung //
//         list         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// queue로 풀 수 있는데 list 연습하려고 후자로 풀었음
// 그냥 list에 넣고 하나씩 삭제하면 됨 다만 iterator가 끝에 다다르면 다시 begin으로 돌아가야 함

#include <iostream>
#include <list>
using namespace std;

int main() {
    int n, k;
    list<int> circle;
    cin >> n >> k;

    for (int i=1; i<=n; i++) circle.push_back(i);
    list<int>::iterator iter = circle.begin();

    cout << "<";
    for (int i=0; i<n; i++) {
        for (int j=0; j<k-1;j++)
            if (++iter == circle.end())
                iter = circle.begin();
        cout << *iter;
        if (i < n-1) cout << ", ";

        iter = circle.erase(iter);
        if (iter == circle.end())
            iter = circle.begin();
    }
    cout << ">";
}
