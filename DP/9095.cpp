#include <bits/stdc++.h>

using namespace std;

int arr[12];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for(int cnt_i=4;cnt_i<=11;cnt_i++){
        arr[cnt_i] = arr[cnt_i-1] + arr[cnt_i-2] + arr[cnt_i-3];
    }

    while(tc--){
        int n;
        cin >> n;

        cout << arr[n] << "\n";
    }

    return 0;
}