#include <bits/stdc++.h>

using namespace std;

int board[100005];
int arr[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int cnt_i=1;cnt_i<=n;cnt_i++){
        cin >> board[cnt_i];
    }

    arr[1] = board[1];

    for(int cnt_i=2;cnt_i<=100000;cnt_i++){
        arr[cnt_i] = arr[cnt_i-1]+ board[cnt_i];
    }

    while(m--){
        int i,j;
        cin >> i >> j;

        cout << arr[j] - arr[i-1] << "\n";
    }

    return 0;
}