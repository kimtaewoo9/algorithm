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
    m=n;

    queue<pair<int,int>> Q;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cin >> board[cnt_i][cnt_j];
        }
    }

    int cnt=0;
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            if(visited[cnt_i][cnt_j] == 0){
                cnt += 1;
                Q.push({cnt_i,cnt_j});
                visited[cnt_i][cnt_j] = 1;

                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first+dx[dir];
                        int ny = cur.second+dy[dir];

                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(board[nx][ny] != board[cur.first][cur.second]) continue;
                        if(visited[nx][ny] != 0) continue;

                        Q.push({nx,ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
    }

    int cnt2=0;
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            visited[cnt_i][cnt_j] = 0;
            if(board[cnt_i][cnt_j] == 'G'){
                board[cnt_i][cnt_j] = 'R';
            }
        }
    }

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            if(visited[cnt_i][cnt_j] == 0){
                cnt2 += 1;
                Q.push({cnt_i,cnt_j});
                visited[cnt_i][cnt_j] = 1;

                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first+dx[dir];
                        int ny = cur.second+dy[dir];

                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(board[nx][ny] != board[cur.first][cur.second]) continue;
                        if(visited[nx][ny] != 0) continue;

                        Q.push({nx,ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
    }

    cout << cnt << " " << cnt2;

    return 0;
}