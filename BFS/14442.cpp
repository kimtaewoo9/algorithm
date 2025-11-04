#include <bits/stdc++.h>

using namespace std;

char board[1005][1005];
int dist[1005][1005][11];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cin >> board[cnt_i][cnt_j];
            fill(dist[cnt_i][cnt_j], dist[cnt_i][cnt_j]+11, -1);
        }
    }

    queue<tuple<int,int,int>> Q;
    Q.push({0,0,0});
    dist[0][0][0] = 0;
    while(!Q.empty()){
        auto [x,y,z] = Q.front(); Q.pop();
        if(x == n-1 && y == m-1){
            cout << dist[x][y][z]+1;
            return 0;
        }
        for(int dir=0;dir<4;dir++){
            int nx = x+dx[dir];
            int ny = y+dy[dir];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;

            if(board[nx][ny] == '1'){
                if(z >= k || dist[nx][ny][z+1] != -1) continue;
                dist[nx][ny][z+1] = dist[x][y][z]+1;
                Q.push({nx,ny,z+1});
            }else{
                if(dist[nx][ny][z] != -1) continue;
                dist[nx][ny][z] = dist[x][y][z]+1;
                Q.push({nx,ny,z});
            }
        }
    }

    cout << -1;

    return 0;
}