/////////////////////////
// 2022.09.04 / kkarung /
//     brute force     //
/////////////////////////
///////////////////////// report ///////////////////////////////
// XXXXXXX 이거 작동 안 됨 첫 번째 예시로 설명하자면 마지막 (3,3) 셀 때 틀림

#include <iostream>
#include <algorithm>
using namespace std;

int checkMaxColumn (char input[][52], int i, int j);
int checkMaxRow (char input[][52], int i, int j);

int main() {
    int N, max=0;
    char input[52][52] = {""};

    cin >> N;


    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            input[i][j] = getchar();
        }
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N-1; j++) {
            int max_column, max_column2, max_row;
            swap(input[i][j], input[i][j+1]); // column swap
            max_column = checkMaxColumn(input, i, j);
            //cout << "\n max_column: " << max_column;
            max_column2 = checkMaxColumn(input, i, j+1);
            max_row = checkMaxRow(input, i, j);
            swap(input[i][j], input[i][j+1]); // undo
            max = (max_column > max) ? max_column : max;
            max = (max_column2 > max) ? max_column2 : max;
            max = (max_row > max) ? max_row : max;
            cout << "\n " << i << ' ' << j << ": " << max << '\n';

        }
    }

    for (int i=1; i<=N-1; i++) {
        for (int j=1; j<=N; j++) {
            int max_column, max_row, max_row2;
            swap(input[i][j], input[i+1][j]); // row swap
            max_column = checkMaxColumn(input, i, j);
            max_row = checkMaxRow(input, i, j);
            max_row2 = checkMaxRow(input, i+1, j);
            swap(input[i][j], input[i+1][j]); // undo

            max = (max_column > max) ? max_column : max;
            max = (max_row > max) ? max_row : max;
            max = (max_row2 > max) ? max_row2 : max;
            cout << "\n " << i << ' ' << j << ": " << max << '\n';
        }
    }

    cout << "\nmax: "<< max << '\n';
    /*for (int i=1; i<=N+1; i++)
        for (int j=1; j<=N+1; j++) {
            cout << input[i][j];
        }*/
}

int checkMaxColumn (char input[][52], int i, int j) {
    int max = 1;
    
    for (int k=i, l=j; input[i][j] == input[k+1][l]; max++, k++) {
    }
    for (int k=i, l=j; input[i][j] == input[k-1][l]; max++, k--) {
    }
    cout << " " << max << "\t";
    return max;
}

int checkMaxRow (char input[][52], int i, int j) {
    int max = 1;
        cout << input[i][j];
    
    for (int k=i, l=j; input[i][j] == input[k][l+1]; max++, l++) {
    }
    for (int k=i, l=j; input[i][j] == input[k][l-1]; max++, l--) {
    }
    cout << " " << max << "\t";
    return max;
}
