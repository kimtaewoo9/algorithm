#include <bits/stdc++.h>

using namespace std;

int dp[10005];
int board[10005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int cnt_i=1;cnt_i<=n;cnt_i++){
        cin >> board[cnt_i];
    }

    dp[1] = board[1]; // 마시는게 당연히 최선
    dp[2] = board[1] + board[2]; // 둘다 마시는게 당연히 최선

    for(int cnt_i=3;cnt_i<=n;cnt_i++){
        // 먹으면 3연속. // 못먹음.
        // 멱으면 2연속.
        // 먹으면 1연속
        dp[cnt_i] = max(dp[cnt_i-2] + board[cnt_i], max(dp[cnt_i-1], dp[cnt_i-3]+board[cnt_i]+board[cnt_i-1]));
    }

    cout << dp[n];

    return 0;
}