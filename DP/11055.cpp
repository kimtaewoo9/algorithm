#include <bits/stdc++.h>

using namespace std;

int dp[1005];
int board[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        cin >> board[cnt_i];
        dp[cnt_i] = board[cnt_i];
    }

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<cnt_i;cnt_j++){
            if(board[cnt_i] > board[cnt_j]){
                dp[cnt_i] = max(dp[cnt_i], dp[cnt_j] + board[cnt_i]);
            }
        }
    }

    int ans=0;
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        ans = max(ans, dp[cnt_i]);
    }

    cout << ans;

    return 0;
}