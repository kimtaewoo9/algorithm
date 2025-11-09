#include <bits/stdc++.h>

using namespace std;

int arr[302][2]; // 1 -> 연속해서 계단을 밟은 경우 
int score[300];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int cnt_i=1;cnt_i<=n;cnt_i++){
        cin >> score[cnt_i];
    }

    arr[1][0] = score[1];
    arr[1][1] = 0; // 점프해서 여기에 온 경우는 없음 .
    arr[2][0] = score[2];
    arr[2][1] = score[1] + score[2];

    for(int cnt_i=3;cnt_i<=300;cnt_i++){
        // 점프인 경우
        arr[cnt_i][0] = max(arr[cnt_i-2][0], arr[cnt_i-2][1]) + score[cnt_i];

        // 연속 이동으로 오는 경우 .. 이경우는 이전 계단은 연속으로 오면 안됨.
        arr[cnt_i][1] = arr[cnt_i-1][0] + score[cnt_i];
    }

    cout << max(arr[n][0], arr[n][1]) << "\n";

    return 0;
}