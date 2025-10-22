#include <bits/stdc++.h>

using namespace std;

int dist[1005][1005];
int dist2[1005][1005];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc=0;
    cin >> tc;

    while(tc--){
        int n,m;
        cin >> m >> n;

        queue<pair<int,int>> Q;
        queue<pair<int,int>> Q2;
    
        for(int cnt_i=0;cnt_i<n;cnt_i++){
            fill(dist[cnt_i], dist[cnt_i]+m ,-1);
            fill(dist2[cnt_i], dist2[cnt_i]+m, -1);
        }

        char board[1005][1005];

        for(int cnt_i=0;cnt_i<n;cnt_i++){
            for(int cnt_j=0;cnt_j<m;cnt_j++){
                cin >> board[cnt_i][cnt_j];
                if(board[cnt_i][cnt_j] == '*'){
                    Q.push({cnt_i, cnt_j});
                    dist[cnt_i][cnt_j] = 1;
                }
                if(board[cnt_i][cnt_j] == '@'){
                    Q2.push({cnt_i, cnt_j});
                    dist2[cnt_i][cnt_j] = 1;
                }
            }
        }

        // 불
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur.first+dx[dir];
                int ny = cur.second+dy[dir];

                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(board[nx][ny] == '#' || dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[cur.first][cur.second]+1;
                Q.push({nx,ny});
            }
        }

        // 상근이
        bool flag = false;
        while(!Q2.empty()){
            auto cur = Q2.front(); Q2.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur.first+dx[dir];
                int ny = cur.second+dy[dir];

                if(nx<0||nx>=n||ny<0||ny>=m){
                    cout << dist2[cur.first][cur.second] << "\n";
                    flag = true;
                    while(!Q2.empty()) Q2.pop();
                    break;
                }
                if(board[nx][ny] == '#' || dist2[nx][ny] != -1) continue;
                // 상근이의 조건 주의 
                if(dist[nx][ny] != -1 && dist2[cur.first][cur.second]+1 >= dist[nx][ny]) continue; // 불이 있으면 갈 수가 없음 .

                dist2[nx][ny] = dist2[cur.first][cur.second]+1;
                Q2.push({nx,ny});
            }
        }

        if(flag == false){
            cout << "IMPOSSIBLE" << "\n";
        }
    }

    return 0;
}