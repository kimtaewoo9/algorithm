#include <bits/stdc++.h>

using namespace std;

int board[100005];
int arr[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        cin >> board[cnt_i];
    }

    arr[0] = board[0];
    int mx=-0x7fffffff;
    for(int cnt_i=1;cnt_i<n;cnt_i++){
        arr[cnt_i] = max(arr[cnt_i-1]+board[cnt_i], board[cnt_i]);
    }

    int ans=-0x7fffffff;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        ans = max(arr[cnt_i], ans);
    }

    cout << ans;
    return 0;
}