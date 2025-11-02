#include <bits/stdc++.h>

using namespace std;

char board[1005][1005];
int dist[1005][1005][2];

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
            
            dist[cnt_i][cnt_j][0] = -1;
            dist[cnt_i][cnt_j][1] = -1;
        }
    }

    // 1, 1 에서 출발
    queue<tuple<int,int,int>> Q;
    dist[0][0][0] = 0;
    Q.push({0,0,0});

    while(!Q.empty()){
        auto [x,y,d] = Q.front(); Q.pop();
        if(x == n-1 && y == m-1){
            cout << dist[x][y][d]+1;
            return 0;
        }
        for(int dir=0;dir<4;dir++){
            int nx = x+dx[dir];
            int ny = y+dy[dir];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny][d] != -1) continue; // 이미 간곳이면 가지 않음 .

            // 벽인 경우 -> 벽 부수는 경우 벽 못부수는 경우
            if(board[nx][ny] == '1' && d == 1) continue;

            // 벽 부수고 가는 경우 
            if(board[nx][ny] == '1' && d == 0){
                dist[nx][ny][1] = dist[x][y][0]+1; // 벽을 부수고감.
                Q.push({nx,ny,1});
            }
            
            // 벽 아닌 경우
            if(board[nx][ny] =='0'){
                dist[nx][ny][d] = dist[x][y][d]+1;
                Q.push({nx,ny,d});
            }
        }
    }

    cout << -1;
    return 0;
}