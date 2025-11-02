#include <bits/stdc++.h>

using namespace std;

int board[302][302];
int board2[302][302];
int visited[302][302];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cin >> board[cnt_i][cnt_j];
        }
    }


    int turn=0;
    while(1){
        turn += 1;
        for(int cnt_i=0;cnt_i<n;cnt_i++){
            fill(visited[cnt_i], visited[cnt_i]+m, 0);
            fill(board2[cnt_i], board2[cnt_i]+m, 0);
        }

        // 동 서 남 북 방향의 물의 수 세기 ..
        for(int cnt_i=0;cnt_i<n;cnt_i++){
            for(int cnt_j=0;cnt_j<m;cnt_j++){
                for(int dir=0;dir<4;dir++){
                    if(board[cnt_i][cnt_j] == 0) continue;
                    int nx = cnt_i+dx[dir];
                    int ny = cnt_j+dy[dir];
                    if(board[nx][ny] == 0) board2[cnt_i][cnt_j] += 1;
                }
            }
        }

        // 빙산 녹이기 .
        for(int cnt_i=0;cnt_i<n;cnt_i++){
            for(int cnt_j=0;cnt_j<m;cnt_j++){
                board[cnt_i][cnt_j] -= board2[cnt_i][cnt_j];
                if(board[cnt_i][cnt_j] < 0) board[cnt_i][cnt_j] = 0;
            }
        }

        // 분리 됐는지 확인
        queue<pair<int,int>> Q;
        int cnt=0;
        for(int cnt_i=0;cnt_i<n;cnt_i++){
            for(int cnt_j=0;cnt_j<m;cnt_j++){
                if(board[cnt_i][cnt_j] != 0 && visited[cnt_i][cnt_j] == 0){
                    cnt += 1;

                    Q.push({cnt_i, cnt_j});
                    visited[cnt_i][cnt_j] = 1;

                    while(!Q.empty()){
                        auto cur = Q.front(); Q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx = cur.first+dx[dir];
                            int ny = cur.second+dy[dir];

                            if(nx<0||nx>=n||ny<0||ny>=m) continue;
                            if(board[nx][ny] == 0 || visited[nx][ny] != 0) continue;
                            
                            Q.push({nx,ny});
                            visited[nx][ny] = 1;
                        }
                    }
                }
            }
        }

        if(cnt == 0){
            cout << 0;
            return 0;
        }
        if(cnt >= 2){
            cout << turn;
            return 0;
        }
    }

    return 0;
}