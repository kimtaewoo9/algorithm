#include <bits/stdc++.h>

using namespace std;

int board[102][102];
int visited[102][102];
int dist[102][102];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n;

    m=n;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cin >> board[cnt_i][cnt_j];
        }
    }

    queue<pair<int,int>> Q;

    int numbering=0;
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            if(board[cnt_i][cnt_j] != 0 && visited[cnt_i][cnt_j] == 0){
                numbering += 1;
                Q.push({cnt_i,cnt_j});
                visited[cnt_i][cnt_j] = 1;
                board[cnt_i][cnt_j] = numbering;
                
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first+dx[dir];
                        int ny = cur.second+dy[dir];

                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(board[nx][ny] != 1 || visited[nx][ny] != 0) continue; // 어차피 섬이니까 0이면 멈추면 됨 .

                        Q.push({nx,ny});
                        visited[nx][ny] = 1;
                        board[nx][ny] = numbering;
                    }
                }
            }
        }
    }

    int mn = 0x7fffffff;
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            if(board[cnt_i][cnt_j] != 0){
                
                for(int cnt_k=0;cnt_k<n;cnt_k++) fill(dist[cnt_k], dist[cnt_k]+m, -1);

                queue<pair<int,int>> Q;
                Q.push({cnt_i,cnt_j});
                dist[cnt_i][cnt_j] = 0;

                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first+dx[dir];
                        int ny = cur.second+dy[dir];

                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(board[nx][ny] == board[cnt_i][cnt_j] || dist[nx][ny] != -1) continue;

                        if(board[nx][ny] != 0){
                            mn = min(mn, dist[cur.first][cur.second]);
                        }

                        Q.push({nx,ny});
                        dist[nx][ny] = dist[cur.first][cur.second]+1;
                    }
                }
            }
        }
    }

    cout << mn;

    return 0;
}