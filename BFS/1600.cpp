#include <bits/stdc++.h>

using namespace std;

int board[202][202];
int dist[202][202][32];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int ddx[8] = {-2,-1,1,2,2,1,-1,-2};
int ddy[8] = {1,2,2,1,-1,-2,-2,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    int n,m;
    cin >> m >> n;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cin >> board[cnt_i][cnt_j];

            fill(dist[cnt_i][cnt_j], dist[cnt_i][cnt_j]+k+1, -1);
        }
    }

    queue<tuple<int,int,int>> Q;
    dist[0][0][0] = 0;
    Q.push({0,0,0});

    while(!Q.empty()){
        auto [x,y,d] = Q.front(); Q.pop();
        if(x == n-1 && y == m-1){
            cout << dist[x][y][d];
            return 0;
        }
        for(int dir=0;dir<4;dir++){
            int nx = x+dx[dir];
            int ny = y+dy[dir];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny] == 1 || dist[nx][ny][d] != -1) continue;

            dist[nx][ny][d] = dist[x][y][d] + 1;
            Q.push({nx,ny,d});
        }
        // 점프할 힘이 남아 있다면 .
        if(d < k){
            for(int dir=0;dir<8;dir++){
                int nx = x+ddx[dir];
                int ny = y+ddy[dir];

                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(board[nx][ny] == 1 || dist[nx][ny][d+1] != -1) continue;

                dist[nx][ny][d+1] = dist[x][y][d] + 1;
                Q.push({nx,ny,d+1});
            }
        }
    }

    cout << -1;

    return 0;
}