#include <bits/stdc++.h>

using namespace std;

long long dp[102];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for(int cnt_i=6;cnt_i<=100;cnt_i++){
        dp[cnt_i] = dp[cnt_i-1] + dp[cnt_i-5];
    }

    while(tc--){
        int n;
        cin >> n;

        cout << dp[n] << "\n";
    }

    return 0;
}