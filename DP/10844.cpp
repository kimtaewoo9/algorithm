#include <bits/stdc++.h>

using namespace std;

long long d[1005][10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int cnt_i=1;cnt_i<=9;cnt_i++){
        d[1][cnt_i] = 1;
    }

    for(int cnt_i=2;cnt_i<=n;cnt_i++){
        for(int cnt_j=0;cnt_j<=9;cnt_j++){
            if(cnt_j != 0){
                d[cnt_i][cnt_j] += d[cnt_i-1][cnt_j-1];
            }
            if(cnt_j != 9){
                d[cnt_i][cnt_j] += d[cnt_i-1][cnt_j+1];
            }
            d[cnt_i][cnt_j] %= 1000000000;
        }
    }

    long long ans=0;
    for(int cnt_i=0;cnt_i<=9;cnt_i++){
        ans += d[n][cnt_i];
    }
    ans %= 1000000000;

    cout << ans;

    return 0;
}