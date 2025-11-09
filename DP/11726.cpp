#include <bits/stdc++.h>

using namespace std;

int arr[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    arr[1] = 1;
    arr[2] = 2;
    for(int cnt_i=3;cnt_i<=1000;cnt_i++){
        arr[cnt_i] = (arr[cnt_i-1] + arr[cnt_i-2])%10007;
    }

    cout << arr[n];

    return 0;
}