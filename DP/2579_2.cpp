#include <bits/stdc++.h>

using namespace std;

int score[302];
int arr[302];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int sum=0;
    for(int cnt_i=1;cnt_i<=n;cnt_i++){
        cin >> score[cnt_i];
        sum += score[cnt_i];
    }

    arr[1] = score[1];
    arr[2] = score[2]; // 2를 밟지 않는 경우 .
    arr[3] = score[3];

    // 4를 밟지 않으려면, 3은 무조건 밟아야함 .

    for(int cnt_i=4;cnt_i<=300;cnt_i++){
        arr[cnt_i] = min(arr[cnt_i-3], arr[cnt_i-2])+score[cnt_i];
    }

    if(n <= 2){
        cout << sum;
    }else{
        cout << sum - min(arr[n-1], arr[n-2]);
    }

    return 0;
}