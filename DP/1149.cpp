#include <bits/stdc++.h>

using namespace std;

int red[1005];
int green[1005];
int blue[1005];

int arr[1005][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int cnt_i=1;cnt_i<=n;cnt_i++){
        cin >> red[cnt_i];
        cin >> green[cnt_i];
        cin >> blue[cnt_i];
    }

    arr[1][0] = red[0];
    arr[1][1] = green[0];
    arr[1][2] = blue[0];

    for(int cnt_i=1;cnt_i<=1000;cnt_i++){
        arr[cnt_i][0] = min(arr[cnt_i-1][1], arr[cnt_i-1][2]) + red[cnt_i];
        arr[cnt_i][1] = min(arr[cnt_i-1][0], arr[cnt_i-1][2]) + green[cnt_i];
        arr[cnt_i][2] = min(arr[cnt_i-1][0], arr[cnt_i-1][1]) + blue[cnt_i];
    }

    cout << min(arr[n][0], min(arr[n][1], arr[n][2]));

    return 0;
}