#include <bits/stdc++.h>

using namespace std;

long long arr[92][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    arr[1][1] = 1;
    for(int cnt_i=2;cnt_i<=90;cnt_i++){
        arr[cnt_i][0] = arr[cnt_i-1][1]+ arr[cnt_i-1][0];
        arr[cnt_i][1] = arr[cnt_i-1][0];
    }

    cout << arr[n][0] + arr[n][1] << "\n";

    return 0;
}