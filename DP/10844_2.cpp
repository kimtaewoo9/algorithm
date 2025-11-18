#include <bits/stdc++.h>

using namespace std;

long long arr[105][10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    arr[1][0] = 0;
    for(int cnt_i=1;cnt_i<=9;cnt_i++){
        arr[1][cnt_i] = 1;
    }

    for(int cnt_i=2;cnt_i<=n;cnt_i++){
        for(int cnt_j=0;cnt_j<=9;cnt_j++){
            if(cnt_j != 0){
                arr[cnt_i][cnt_j] += arr[cnt_i-1][cnt_j-1];
            }
            if(cnt_j != 9){
                arr[cnt_i][cnt_j] += arr[cnt_i-1][cnt_j+1];
            }
            arr[cnt_i][cnt_j] %= 1000000000;
        }
    }

    long long ans=0;
    for(int cnt_i=0;cnt_i<=9;cnt_i++){
        ans += arr[n][cnt_i];
    }
    ans %= 1000000000;

    cout << ans;

    return 0;
}