#include <bits/stdc++.h>

using namespace std;

char board[105][105];
int visited[105][105];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n;
    m = n;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cin >> board[cnt_i][cnt_j];
        }
    }

    queue<pair<int,int>> Q;
    
    // 색맹 아닌 사람
    int ans1 = 0;
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            if(visited[cnt_i][cnt_j] == 0){
                ans1 += 1;
                Q.push({cnt_i,cnt_j});
                visited[cnt_i][cnt_j] = 1;

                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first+dx[dir];
                        int ny = cur.second+dy[dir];

                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(visited[nx][ny] != 0) continue;
                        if(board[nx][ny] != board[cur.first][cur.second]) continue;

                        visited[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }

    // 색맹인 사람
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            if(board[cnt_i][cnt_j] == 'G'){
                board[cnt_i][cnt_j] = 'R';
            }
        }
    }

    for(int cnt_i=0;cnt_i<n;cnt_i++) fill(visited[cnt_i], visited[cnt_i]+m, 0);

    int ans2=0;
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            if(visited[cnt_i][cnt_j] == 0){
                ans2 += 1;
                Q.push({cnt_i,cnt_j});
                visited[cnt_i][cnt_j] = 1;

                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first+dx[dir];
                        int ny = cur.second+dy[dir];

                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(visited[nx][ny] != 0) continue;
                        if(board[nx][ny] != board[cur.first][cur.second]) continue;

                        visited[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }

    cout << ans1 << " " << ans2;

    return 0;
}