#include <bits/stdc++.h>

using namespace std;

int board[52][52];


int dx[4] = {0,1,0,-1}; // 북 동 남 서 .. 왼쪽으로 가려면 -1 
int dy[4] = {1,0,-1,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, d;
    cin >> n >> d; // 북 동 남 서 순서 ..
    m=n;

    int r,c;
    cin >> r >> c;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cin >> board[cnt_i][cnt_j];
        }
    }

    // 청소한 격자 칸의 개수를 

    int cnt=0;

    while(1){

        if(board[r][c] == 0){
        board[r][c] = -1; // 현재 위치를 청소함 .
        cnt += 1;
        }

        bool flag = false;
        for(int cnt_i=0;cnt_i<4;cnt_i++){
            d = (d+3)%4;
            if(board[r+dx[d]][c+dy[d]] == 0){
                flag = true; // 청소할 곳이 있음.
                break;
            }
        }

        if(flag == false){
            if(board[r-dx[d]][c-dy[d]] == 1){
                cout << cnt << "\n";
                return 0;
            }else{
                r -= dx[d]; // 후진 함 .
                c -= dy[d];
            }
        }else{
            r += dx[d];
            c += dy[d];
        }
    }
}