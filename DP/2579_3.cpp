#include <bits/stdc++.h>

using namespace std;

int board[302];
int dp[302][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int cnt_i=1;cnt_i<=n;cnt_i++){
        cin >> board[cnt_i];
    }

    dp[1][0] = board[1];
    dp[1][1] = 0; // 점프로 온 경우
    dp[2][0] = board[1] + board[2];
    dp[2][1] = board[2]; // 점프로 온 경우 

    // 걸어온 경우 vs 점프로 온 경우
    for(int cnt_i=3;cnt_i<=n;cnt_i++){
        dp[cnt_i][0] = dp[cnt_i-1][1] + board[cnt_i];
        dp[cnt_i][1] = max(dp[cnt_i-2][1], dp[cnt_i-2][0]) + board[cnt_i]; 
    }

    cout << max(dp[n][0], dp[n][1]);


    return 0;
}