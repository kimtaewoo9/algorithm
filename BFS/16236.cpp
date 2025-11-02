#include <bits/stdc++.h>

using namespace std;

int board[22][22];
int dist[22][22];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n;
    m = n;

    for(int cnt_i=0;cnt_i<n;cnt_i++) fill(dist[cnt_i], dist[cnt_i]+m, -1);
    
    queue<pair<int,int>> Q;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cin >> board[cnt_i][cnt_j];
            if(board[cnt_i][cnt_j] == 9){
                Q.push({cnt_i,cnt_j});
                dist[cnt_i][cnt_j] = 0;
                board[cnt_i][cnt_j] = 0; // 아기상어 처음 위치 0으로 초기화.
            }
        }
    }

    int size = 2; // 아기 상어의 처음 사이즈는 2
    int exp = 0; // 아기 상어의 경험치
    int ans = 0; // 정답 (총 이동거리)

    while(1){
        // 탐색 .

        if(exp == size){
            size += 1;
            exp = 0;
        }

        int mn = 0x7fffffff; // 가장 가까운 먹이까지의 거리

        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            if(board[cur.first][cur.second] != 0 && board[cur.first][cur.second] < size && mn > dist[cur.first][cur.second]){
                mn = dist[cur.first][cur.second];
            }
            for(int dir=0;dir<4;dir++){
                int nx = cur.first+dx[dir];
                int ny = cur.second+dy[dir];

                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(board[nx][ny] > size || dist[nx][ny] != -1) continue; 

                Q.push({nx,ny});
                dist[nx][ny] = dist[cur.first][cur.second]+1;
            }
        }

        bool flag = false;

        for(int cnt_i=0;cnt_i<n;cnt_i++){
            for(int cnt_j=0;cnt_j<m;cnt_j++){
                if(dist[cnt_i][cnt_j] == mn && size > board[cnt_i][cnt_j] && board[cnt_i][cnt_j] != 0){
                    ans += dist[cnt_i][cnt_j];

                    for(int cnt_k=0;cnt_k<n;cnt_k++) fill(dist[cnt_k], dist[cnt_k]+m, -1);

                    Q.push({cnt_i,cnt_j});
                    board[cnt_i][cnt_j] = 0;
                    dist[cnt_i][cnt_j] = 0;
                    flag = true;
                    exp += 1;
                    break;
                }
            }
            if(flag) break;
        }

        if(!flag) break;
    }

    cout << ans << "\n";

    return 0;
}