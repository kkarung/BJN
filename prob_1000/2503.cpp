/////////////////////////
// 2022.09.04 / kkarung /
//     brute force     //
/////////////////////////
///////////////////////// report ///////////////////////////////
// 111~999 숫자가 입력에서 주어진 모든 경우와 동일하면 카운트하는 방법
// isDiff로 0이 포함되었는지, 세 자리가 서로 다른지 확인하고
// isPossible로 정답 후보일 수 있는지 확인한다
// 생각해 볼 수 있는 케이스 1
// 2
// 123 0 0
// 456 0 0
// 생각해 볼 수 있는 케이스 2
// 4
// 714 1 0
// 221 0 3
// 562 1 0
// 386 0 0

#include <iostream>
#include <set>
using namespace std;

bool isDiff(int);
bool isPossible(int, int, int[][3]);

int main() {
    int n, output = 0;
    int input[100][3] = {0};

    cin >> n; //324,328

    for (int i=0; i<n; i++)
        for (int j=0; j<3; j++)
            cin >> input[i][j];

    for (int cand=111; cand<1000; cand++) {
        int possibility = 0;;
        for (int qst=0; qst<n; qst++) {
            if (isDiff(cand) && isPossible(cand, qst, input)) {
                possibility++;
                if (possibility == n) {
                    output++;
                }
            }
        }
    }

    cout << output << "\n";
}

bool isDiff(int cand) {
    bool retn = true;
    if (cand/10%10==0 || cand%10==0) retn = false;
    if (cand/100==cand/10%10||cand/10%10==cand%10||cand/100==cand%10) retn = false;

    return retn;
}

bool isPossible(int cand, int qst, int input[100][3]) {
    int stk = 0, n=0;
    int qstPool[3]={0};
    int candPool[3]={0};
    set<int> ball;
    
    if ((cand/100)==(input[qst][0]/100)) stk++;
    else {
        candPool[n] = cand/100;
        qstPool[n++] = input[qst][0]/100;
    }
    if ((cand/10%10)==(input[qst][0]/10%10)) stk++;
    else {
        candPool[n] = cand/10%10;
        qstPool[n++] = input[qst][0]/10%10;
    }
    if ((cand%10)==(input[qst][0]%10)) stk++;
    else {
        candPool[n] = cand%10;
        qstPool[n++] = input[qst][0]%10;
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (candPool[i]==qstPool[j] && candPool[i]>0)
                ball.insert(i);

    if (stk==input[qst][1] && ball.size()==input[qst][2]) return true;
    else return false;
}
