#include <bits/stdc++.h>

using namespace std;

int board[502][502];
int arr[502][502];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int cnt_i=1;cnt_i<=n;cnt_i++){
        for(int cnt_j=1;cnt_j<=cnt_i;cnt_j++){
            cin >> board[cnt_i][cnt_j];
        }
    }

    arr[1][1] = board[1][1];
    arr[2][1] = board[1][1] + board[2][1];
    arr[2][2] = board[1][1] + board[2][2];

    for(int cnt_i=3;cnt_i<=n;cnt_i++){
        for(int cnt_j=1;cnt_j<=cnt_i;cnt_j++){
            arr[cnt_i][cnt_j] = max(arr[cnt_i-1][cnt_j-1], arr[cnt_i-1][cnt_j]) + board[cnt_i][cnt_j];
        }
    }

    int ans=0;
    for(int cnt_i=1;cnt_i<=n;cnt_i++){
        if(ans < arr[n][cnt_i]) ans = arr[n][cnt_i];
    }

    return 0;
}