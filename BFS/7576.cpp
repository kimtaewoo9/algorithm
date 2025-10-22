#include <bits/stdc++.h>

using namespace std;

int board[1005][1005];
int dist[1005][1005];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ans=0;
    int n,m;
    cin >> m >> n;

    for(int cnt_i=0;cnt_i<n;cnt_i++) fill(dist[cnt_i], dist[cnt_i]+m,-1);

    queue<pair<int,int>> Q;
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cin >> board[cnt_i][cnt_j];
            if(board[cnt_i][cnt_j] == 1){
                Q.push({cnt_i,cnt_j});
                dist[cnt_i][cnt_j] = 0;
            }
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.first+dx[dir];
            int ny = cur.second+dy[dir];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny] == -1 || dist[nx][ny] != -1) continue;

            Q.push({nx,ny});
            dist[nx][ny] = dist[cur.first][cur.second]+1;
        }
    }

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            if(board[cnt_i][cnt_j] != -1 && dist[cnt_i][cnt_j] == -1){
                cout << -1 << "\n";
                return 0;
            }
            ans = max(ans, dist[cnt_i][cnt_j]);
        }
    }

    cout << ans;

    return 0;
}