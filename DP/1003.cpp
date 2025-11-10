#include <bits/stdc++.h>

using namespace std;

int one[42];
int zero[42];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    zero[0] = 1; one[0] = 0;
    zero[1] = 0; one[1] = 1;

    for(int cnt_i=2;cnt_i<=40;cnt_i++){
        zero[cnt_i] = zero[cnt_i-1] + zero[cnt_i-2];
        one[cnt_i] = one[cnt_i-1] + one[cnt_i-2];
    }

    int tc;
    cin >> tc;

    while(tc--){
        int n;
        cin >> n;

        cout << zero[n] << " " << one[n] << "\n";
    }

    return 0;
}