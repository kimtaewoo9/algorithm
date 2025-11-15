#include <bits/stdc++.h>

using namespace std;

int t[20];
int p[20];
int d[20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int cnt_i=1;cnt_i<=n;cnt_i++){
        cin >> t[cnt_i];
        cin >> p[cnt_i];
    }

    // d[cnt_i] -> cnt_i 번째에 상담을 했을때 .. 최댓값 ! 
    for(int cnt_i=n;cnt_i>=1;cnt_i--){
        if(cnt_i+t[cnt_i] <= n+1){
            // 상담이 가능 할때 .. 
            d[cnt_i] = max(d[cnt_i+t[cnt_i]] + p[cnt_i], d[cnt_i+1]);
        }else{
            d[cnt_i] = d[cnt_i+1];
        }
    }

    int ans=0;
    for(int cnt_i=1;cnt_i<=n;cnt_i++){
        ans = max(ans, d[cnt_i]);
    }

    cout << ans;

    return 0;
}