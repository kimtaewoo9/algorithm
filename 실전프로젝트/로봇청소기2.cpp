#include <bits/stdc++.h>

using namespace std;

int board[52][52];
int visited[52][52];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int n,m;
    cin >> n >> m;
    int x,y,d;
    cin >> x >> y >> d;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cin >> board[cnt_i][cnt_j];
        }
    }
    int ans=0; // 청소한 칸의 개수
    while(1){
        bool isclean=0;
        if(board[x][y] == 0){
            ans++;
            board[x][y] = -1; // 청소해줍니다.
        }
        // 빈칸이 있는지 확인
        for(int cnt_i=0;cnt_i<4;cnt_i++){
            d = (d+3)%4; // 반시계 방향으로 회전.
            if(board[x+dx[d]][y+dy[d]] == 0){
                // 청소할 곳이 있으면
                isclean=1; // 청소할 곳 있다고 표시 해주고
                break;
            }
        }
        if(isclean){
            // 청소할 곳으로 이동해줌
            x += dx[d];
            y += dy[d];
            continue;
        }
        else{
            // 후진해줍니다.
            if(board[x-dx[d]][y-dy[d]] == 1) break;
            x -= dx[d];
            y -= dy[d];
        }
    }
    cout << ans;
    return 0;
}