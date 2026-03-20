#include <bits/stdc++.h>

using namespace std;

char board[502][502];
int dist[502][502];

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

    // 시작은 항상 마지막행 첫번째열 .
    queue<pair<int,int>> Q;
    Q.push({n-1,0});
    dist[n-1][0] = 1;

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();

        // 1번 규칙으로 가는 경우 .
        for(int dir=0;dir<4;dir++){
            int nx = cur.first+dx[dir];
            int ny = cur.second+dy[dir];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny] != 'H' || dist[nx][ny] != 0) continue;
            
            Q.push({nx,ny});
            dist[nx][ny] = dist[cur.first][cur.second]+1;
        }
        
        // 2번 규칙으로 가는 경우
        // 2칸 또는 3칸 떨어진 곳으로 갈 수 있음 .
        // 2칸 이동 규칙 .. 좌와 우로 또 나눠야함 .
        // 2칸 이동 + 좌로 이동 .
        if(cur.first-1>=0||cur.second-2>=0){
            if(board[cur.first][cur.second-2] == 'H' && board[cur.first][cur.second-1] == '.'){
                if(board[cur.first-1][cur.second] == '.' || board[cur.first-1][cur.second-1] == '.' || board[cur.first-1][cur.second-2] == '.'){
                    if(dist[cur.first][cur.second-2] == 0){
                        Q.push({cur.first, cur.second-2});
                        dist[cur.first][cur.second-2] = dist[cur.first][cur.second]+1;
                    }
                }
                
            }
        }

        // 2칸 이동 + 우로 이동 ..
        if(cur.first-1>=0||cur.second+2<m){
            if(board[cur.first][cur.second+2] == 'H' && board[cur.first][cur.second+1] == '.'){
                if(board[cur.first-1][cur.second] == '.' || board[cur.first-1][cur.second+1] == '.' || board[cur.first-1][cur.second+2] == '.'){
                    if(dist[cur.first][cur.second+2] == 0){
                        Q.push({cur.first, cur.second+2});
                        dist[cur.first][cur.second+2] = dist[cur.first][cur.second]+1;
                    }
                }
                
            }
        }
        // 3칸 이동 + 좌로 이동 .
        if(cur.first-1>=0||cur.second-3>=0){
            if(board[cur.first][cur.second-3] == 'H' && board[cur.first][cur.second-1] == '.' && board[cur.first][cur.second-2] == '.'){
                if(board[cur.first-1][cur.second] == '.' || board[cur.first-1][cur.second-1] == '.' || board[cur.first-1][cur.second-2] == '.'){
                    if(dist[cur.first][cur.second-3] == 0){
                        Q.push({cur.first, cur.second-3});
                        dist[cur.first][cur.second-3] = dist[cur.first][cur.second]+1;
                    }
                }
                
            }
        }

        // 3칸 이동 + 우로 이동.
        if(cur.first-1>=0||cur.second+3<m){
            if(board[cur.first][cur.second+3] == 'H' && board[cur.first][cur.second+1] == '.' && board[cur.first][cur.second+2] == '.'){
                if(board[cur.first-1][cur.second] == '.' || board[cur.first-1][cur.second+1] == '.' || board[cur.first-1][cur.second+2] == '.'){
                    if(dist[cur.first][cur.second+3] == 0){
                        Q.push({cur.first, cur.second+3});
                        dist[cur.first][cur.second+3] = dist[cur.first][cur.second]+1;
                    }
                }
            }
        }

        // 3번 규칙으로 가는 경우
        if(cur.first-2>=0){
            if(board[cur.first-1][cur.second] == '.' && board[cur.first-2][cur.second] == 'H'){
                if(dist[cur.first-2][cur.second] == 0){
                    Q.push({cur.first-2, cur.second});
                    dist[cur.first-2][cur.second] = dist[cur.first][cur.second]+1;
                }
            }
        }

        // 4번 규칙으로 가는 경우
        // 왼쪽 칸과 .. 윗 칸 .
        if(cur.first-1>=0 && cur.second-1>=0){
            if(board[cur.first-1][cur.second] == '.' && board[cur.first][cur.second-1] == '.' && board[cur.first-1][cur.second-1] == 'H'){
                if(dist[cur.first-1][cur.second-1] == 0){
                    Q.push({cur.first-1, cur.second-1});
                    dist[cur.first-1][cur.second-1] = dist[cur.first][cur.second]+1;
                }
            }
        }
        // 오른쪽 칸과 윗 칸 ..
        if(cur.first-1>=0 && cur.second+1<m){
            if(board[cur.first-1][cur.second] == '.' && board[cur.first][cur.second+1] == '.' && board[cur.first-1][cur.second+1] == 'H'){
                if(dist[cur.first-1][cur.second+1] == 0){
                    Q.push({cur.first-1, cur.second+1});
                    dist[cur.first-1][cur.second+1] = dist[cur.first][cur.second]+1;
                }
            }
        }
    }

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            if(board[cnt_i][cnt_j] == 'H' && dist[cnt_i][cnt_j] == 0) dist[cnt_i][cnt_j] = -1;
            cout << dist[cnt_i][cnt_j] << " ";
        }
        cout << "\n";
    }

    return 0;
}