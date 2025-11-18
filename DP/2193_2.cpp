#include <bits/stdc++.h>

using namespace std;

long long dp[92][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    dp[1][1] = 1;
    for(int cnt_i=2;cnt_i<=90;cnt_i++){
        dp[cnt_i][0] = dp[cnt_i-1][0] + dp[cnt_i-1][1];
        dp[cnt_i][1] = dp[cnt_i-1][0];
    }

    cout << dp[n][0] + dp[n][1] << "\n";

    return 0;
}