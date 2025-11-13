#include <bits/stdc++.h>

using namespace std;

int board[1005];
int dp[1005];

int main(){
    int n;
    cin >> n;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        cin >> board[cnt_i];
        dp[cnt_i] = 1;
    }

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<cnt_i;cnt_j++){
            if(board[cnt_i] > board[cnt_j]){
                dp[cnt_i] = max(dp[cnt_j]+1, dp[cnt_i]);
            }
        }
    }

    int ans=0;
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        ans = max(dp[cnt_i], ans);
    }

    cout << ans;
    
    return 0;
}