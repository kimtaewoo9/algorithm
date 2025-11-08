#include <bits/stdc++.h>

using namespace std;

int arr[1000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;

    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;

    for(int cnt_i=4;cnt_i<=1000000;cnt_i++){
        if(cnt_i%3 == 0 && cnt_i%2 == 0){
            arr[cnt_i] = min(arr[cnt_i/3]+1, min(arr[cnt_i/2]+1,arr[cnt_i-1]+1));
        }
        else if(cnt_i%3==0){
            arr[cnt_i] = min(arr[cnt_i/3]+1, arr[cnt_i-1]+1);
        }
        else if(cnt_i%2 == 0){
            arr[cnt_i] = min(arr[cnt_i/2]+1, arr[cnt_i-1]+1);
        }
        else{
            arr[cnt_i] = arr[cnt_i-1]+1;
        }
    }

    cout << arr[x];

    return 0;
}