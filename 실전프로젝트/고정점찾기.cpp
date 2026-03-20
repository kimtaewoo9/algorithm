#include <bits/stdc++.h>

using namespace std;

int board[400005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // 정렬되어있고 .. 서로 다르다.
    bool flag = false;
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        cin >> board[cnt_i];
        if(board[cnt_i] == cnt_i){
            cout << cnt_i << " ";
            flag = false;
        }
    }

    // for(int cnt_i=10;cnt_i<200000;cnt_i++){
    //     if(board[cnt_i] == cnt_i){
    //         cout << board[cnt_i] <<  " ";
    //         flag = true;
    //     }
    // }

    if(!flag) cout << -1;

    return 0;
}